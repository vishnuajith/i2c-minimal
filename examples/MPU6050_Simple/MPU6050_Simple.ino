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
    i2cwrite(0x68 << 1 | 0, 0x6B, 0x00);                                  //Power Management     // ( device_id<<1|0 , address , data )
    AcX = i2cread(0x68 << 1 | 1, 0x3B);                                   //X Axis Accelerometer // (device_id<<1|1, address)
    AcY = i2cread(0x68 << 1 | 1, 0x3D);                                   //Y Axis Accelerometer // (device_id<<1|1, address)
    AcZ = i2cread(0x68 << 1 | 1, 0x3F);                                   //Z Axis Accelerometer // (device_id<<1|1, address)
    Tem = (i2cread(0x68 << 1 | 1, 0x41)) / 340 + 36.53;                   //Temperature          // (device_id<<1|1, address)
    GyX = i2cread(0x68 << 1 | 1, 0x43);                                   //X Axis Gyroscope     // (device_id<<1|1, address)
    GyY = i2cread(0x68 << 1 | 1, 0x45);                                   //Y Axis Gyroscope     // (device_id<<1|1, address)
    GyZ = i2cread(0x68 << 1 | 1, 0x47);                                   //Z Axis Gyroscope     // (device_id<<1|1, address)



    Serial.print("########################################\n");
    Serial.print("AcX="); Serial.print(AcX); Serial.print("| AcY="); Serial.print(AcY); Serial.print("| AcZ="); Serial.print(AcZ);Serial.print("\n");
    Serial.print("\t Tem="); Serial.print(Tem);Serial.print("\n");
    Serial.print("GyX="); Serial.print(GyX); Serial.print("| GyY="); Serial.print(GyY); Serial.print("| GyZ="); Serial.print(GyZ);Serial.print("\n");

}
