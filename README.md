# i2c minimal 
[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-informational.svg)](https://opensource.org/licenses/)  [![PR's Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat)](http://makeapullrequest.com)

Bare minimum library for Arduino. Uses only half of the memory than wire library.

This is first version of library . Frequency is set default at 400kHz.

 
There are only few functions in this library ,but are sufficient for all applications and will make the code occupy less space.


**Function List** :
| Name      | Descriptoin           | Usage |
| ------------- |:-------------:| :-----:|
| init()     | Initialize library | `i2c.init();` |
| start()     | To Start Communication     |   `i2c.start(<device_address>);` |
| write() | Write data to the connected I2C device      |   `i2c.write<data>);` |
| readack() | Read with Acknowledge      |    `i2c.readack();` |
| readnck() | Read without Acknowledge      |    `i2c.readnck();` |
| stop() | Stops I2C Communication     |    `i2c.stop();` |

Needs help in making more example code and refining the code so if you want to **contribute** you are welcomed.

[![Open Source](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://opensource.org/)  :rocket:

[![GitHub stars](https://img.shields.io/github/stars/vishnuajith/i2c-minimal?style=social&label=Star)](https://github.com/vishnuajith/MyBadges) [![GitHub watchers](https://img.shields.io/github/watchers/vishnuajith/i2c-minimal?style=social&label=Watch)](https://github.com/vishnuajith/MyBadges) [![GitHub forks](https://img.shields.io/github/forks/vishnuajith/i2c-minimal?style=social&label=Fork)](https://github.com/vishnuajith/MyBadges) [![GitHub followers](https://img.shields.io/github/followers/vishnuajith?style=social&label=Follow)](https://github.com/vishnuajith/MyBadges) 
