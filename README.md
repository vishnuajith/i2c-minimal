# i2c
i2c library for Arduino

This is first edition of library .As now i2c frequency is default set at 400kHz.

Usage:

    For Begining I2C Communication use i2c.init();


    To Start Communication to a device use i2c.start(<device_address>);


    Write to I2C device using i2c.write(<data>);


    Read with Acknowledge using i2c.readack();


    Read without Acknowledge using i2c.readnck();


    Stop I2C Communication use i2c.stop();


