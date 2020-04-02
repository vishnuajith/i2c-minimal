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
    i2c.init();
}

void loop() {
    i2c.start(0x68 << 1 | 0);
    i2c.write(0x6B);                                                         //Power Management     
    i2c.write(0x00);
    i2c.stop();
    
    i2c.start(0x68 << 1 | 0);
    i2c.write(0x3B);                                                         //Writing address of the register to start reading
    i2c.start(0x68 << 1 | 1);                                                //Starting i2c communication and reading all registers
    AcX = i2c.readack()<<8 | i2c.readack();                                   //X Axis Accelerometer 
    AcY = i2c.readack()<<8 | i2c.readack();                                   //Y Axis Accelerometer 
    AcZ = i2c.readack()<<8 | i2c.readack();                                   //Z Axis Accelerometer 
    Tem = (i2c.readack()<<8 | i2c.readack()) / 340 + 36.53;                   //Temperature          
    GyX = i2c.readack()<<8 | i2c.readack();                                   //X Axis Gyroscope     
    GyY = i2c.readack()<<8 | i2c.readack();                                   //Y Axis Gyroscope     
    GyZ = i2c.readack()<<8 | i2c.readnck();                                   //Z Axis Gyroscope    
    i2c.stop();                                                              //Ending i2c communications



    Serial.print("########################################\n");
    Serial.print("AcX="); Serial.print(AcX); Serial.print("| AcY="); Serial.print(AcY); Serial.print("| AcZ="); Serial.print(AcZ);Serial.print("\n");
    Serial.print("\t Tem="); Serial.print(Tem);Serial.print("\n");
    Serial.print("GyX="); Serial.print(GyX); Serial.print("| GyY="); Serial.print(GyY); Serial.print("| GyZ="); Serial.print(GyZ);Serial.print("\n");

}
