/*
  i2c.h - i2c library for Arduino
  Copyright (c) 2020 Vishnu Ajith.  All right reserved.
*/
#ifndef i2c_h
#define i2c_h
#define LIBRARY_VERSION	1.0.0

#include <inttypes.h>

#define CPU 16000000UL
#define I2CFREQ 400000UL
#define BAUD 9600
#define twbr ((CPU / I2CFREQ) - 16) / 2

void i2cinit(void);
uint16_t i2cread(uint8_t, uint8_t);
void i2cwrite(uint8_t, uint8_t, uint8_t);
void i2cstop(void);


#endif

