/*
 * Example code for MPU 6050
 * Author : Vishnu Ajith
 */
#include<i2c.h>

int16_t data = 0;
int16_t AcX = 0;
int16_t AcY = 0;
int16_t AcZ = 0;
int16_t GyX = 0;
int16_t GyY = 0;
int16_t GyZ = 0;
int16_t Tem = 0;

void setup() {
    Serial.begin(9600);
    i2cinit();
}

void loop() {
    i2cstart(0x68 << 1 | 0);
    i2cwrite(0x6B);                                                         //Power Management     
    i2cwrite(0x00);
    i2cstop();
    
    i2cstart(0x68 << 1 | 0);
    i2cwrite(0x3B);                                                         //Writing address of the register to start reading
    i2cstart(0x68 << 1 | 1);                                                //Starting i2c communication and reading all registers
    AcX = i2creadack()<<8 | i2creadack();                                   //X Axis Accelerometer 
    AcY = i2creadack()<<8 | i2creadack();                                   //Y Axis Accelerometer 
    AcZ = i2creadack()<<8 | i2creadack();                                   //Z Axis Accelerometer 
    Tem = (i2creadack()<<8 | i2creadack()) / 340 + 36.53;                   //Temperature          
    GyX = i2creadack()<<8 | i2creadack();                                   //X Axis Gyroscope     
    GyY = i2creadack()<<8 | i2creadack();                                   //Y Axis Gyroscope     
    GyZ = i2creadack()<<8 | i2creadnck();                                   //Z Axis Gyroscope    
    i2cstop();                                                              //Ending i2c communications



    Serial.print("########################################\n");
    Serial.print("AcX="); Serial.print(AcX); Serial.print("| AcY="); Serial.print(AcY); Serial.print("| AcZ="); Serial.print(AcZ);Serial.print("\n");
    Serial.print("\t Tem="); Serial.print(Tem);Serial.print("\n");
    Serial.print("GyX="); Serial.print(GyX); Serial.print("| GyY="); Serial.print(GyY); Serial.print("| GyZ="); Serial.print(GyZ);Serial.print("\n");

}
