/*
  i2c.h - I2C library for arduino
  Copyright (c) 2020 Vishnu Ajith.  All right reserved.
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
*/

#include "i2c.h"

#include "avr/io.h"


void i2cinit() {
  TWBR = twbr;                                                           // Set Baud Rate for transmission
  TWCR = (1 << TWEN);                                                    // Set Two Wire Enable (not necessary)

}
void i2cwrite(uint8_t device, uint8_t address, uint8_t data) {

  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);                      //Send start command
  while (!(TWCR & (1 << TWINT)));

  TWDR = device;                                                         //Send device id
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));

  TWDR = address;                                                        //Send address
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));

  TWDR = data;                                                           //Send data
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));

  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);                      //Send stop command
  while ((TWCR & (1 << TWINT)));      

}

uint16_t i2cread(uint8_t device, uint8_t address) {
  
  uint16_t data;

  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);                      //Send start command
  while (!(TWCR & (1 << TWINT)));

  TWDR = device & 0xFE;                                                  //Send device id
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));

  TWDR = address;                                                        //Send address
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));

  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);                      //Send start command
  while (!(TWCR & (1 << TWINT)));

  TWDR = device;                                                         //Send device id
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));

  TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);                       //readack
  while (!(TWCR & (1 << TWINT)));
  data = TWDR << 8;

  TWCR = (1 << TWINT) | (1 << TWEN);                                     //readNck
  while (!(TWCR & (1 << TWINT)));
  data |= TWDR;

  TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);                      // Sending stop conditon
  while ((TWCR & (1 << TWINT)));

  return data;
}

int i2cwritestr(char *str) {
  int n = 0;
  while (str[n] != '\0') {
    while ((UCSR0A & (1 << UDRE0)) == 0) {}
    UDR0 = str[n];
    n++;
  }
}

void i2cstop() {

  TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);                      // Sending stop conditon
  while ((TWCR & (1 << TWINT)));

}




