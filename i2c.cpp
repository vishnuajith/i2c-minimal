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

//Including Header file
#include "i2c.h"


#include "avr/io.h"


void iic::init() {
  TWBR = twbr;                                                           // Set Baud Rate for transmission
  TWCR = (1 << TWEN);                                                    // Set Two Wire Enable (not necessary)

}

iic::iic(){
//constructor
}

void iic::start(uint8_t device){
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);                      //Send start command
  while (!(TWCR & (1 << TWINT)));
  TWDR = device;                                                         //Send device id
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));
}

void iic::write(uint8_t data) {
  TWDR = data;                                                           //Send data
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));
}

uint8_t iic::readack() {
  uint8_t data;
  TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);                       //readack
  while (!(TWCR & (1 << TWINT)));
  data = TWDR;
  return data;
}

uint8_t iic::readnck() {
  uint8_t data;
  TWCR = (1 << TWINT) | (1 << TWEN);                                     //readNck
  while (!(TWCR & (1 << TWINT)));
  data = TWDR;
  return data;
}

void iic::stop(){  
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);                      //Send stop command
  while ((TWCR & (1 << TWINT)));      
}


//Preinstantiate Objects
iic i2c = iic();

