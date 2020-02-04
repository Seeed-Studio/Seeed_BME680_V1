BME680:  [![Build Status](https://travis-ci.com/Seeed-Studio/Seeed_BME680_V1.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Seeed_BME680_V1)
===========
![BME680](https://github.com/linux-downey/BME680_4_In_1_Sensor_Drv/blob/master/BME680_module.png)  

BME680 is an integrated environmental sensor developed specifically for mobile applications and wearables where size and low power consumption are key requirements.It also supports four kinds of numerical measurements of temperature, humidity, gas and air pressure.  

Before use:
===============
>* **This library only supports ATmega2560-arduino board.**
>* At first ,you need to create a folder bsec\atmega2560 at ARDUINO_INSTALL_DIR\Arduino\hardware\arduino\avr\libraries\,the ARDUINO_INSTALL_DIR is the directory that arduino IDE installed.
>* Copy the libalgobsec.a to the ARDUINO_INSTALL_DIR\Arduino\hardware\arduino\avr\libraries\bsec\atmega2560
>* Edit the file platform.txt at ARDUINO_INSTALL_DIR\Arduino\hardware\arduino\avr\,replace the 68th line:  
recipe.c.combine.pattern="{compiler.path}{compiler.c.elf.cmd}" {compiler.c.elf.flags} -mmcu={build.mcu} {compiler.c.elf.extra_flags} -o "{build.path}/{build.project_name}.elf" {object_files} "{build.path}/{archive_file}" "-L{build.path}" -lm  
with:  
recipe.c.combine.pattern="{compiler.path}{compiler.c.elf.cmd}" {compiler.c.elf.flags} -mmcu={build.mcu} {compiler.c.elf.extra_flags} -o "{build.path}/{build.project_name}.elf" {object_files} "{build.path}/{archive_file}" "-L{build.path}" -lm -L{runtime.platform.path}\libraries\bsec\\{build.mcu} -lalgobsec  
Link this library during compilation.
**Compile error will occur without operations above.**
**If you are still confuse about how to add the .a library,please refer to doc/BST-BME680-library-usage.pdf**


Usage:
==========
***This Bme680 version only supports IIC communication protocols.***
There are two arduino examples for different usecase.
>1. basic:This sketch is the basic example to perform measurement,the problem is that the result of gas value may be inaccurate.Because the gas measurement depends on a baseline which stored in the host,the baseline can be seen as compensation.
>2. basic_config_state:Compare to the basic,this example will store the baseline regular.Baseline will be loaded after the host restarts.This example is recommended when user wants to


Note:
===========
>* **The sensor needs to be calibrated for 5 days when it first uses.The sensor value is not accurate before/during calibration.**
>* Need to wait about 2mins after module power on that gas heater enter a steady state.The gas value at this time is correct
>* The IAQ value corresponding air quality:
    0-50       -     good
    51-100     -     average
    101-150    -     little bad
    151-200    -     bad
    201-300    -     worse
    301-500    -     very bad

****
reference:
=============
**Datasheet:doc/BST-BME680-datasheet.pdf**

statement:
==========
This software is written by downey for seeed studio and is licensed under The MIT License. Check License.txt for more information.

Contributing to this software is warmly welcomed. You can do this basically by
forking, committing modifications and then pulling requests (follow the links above
for operating guide). Adding change log and your contact into file header is encouraged.
Thanks for your contribution.

Seeed is a hardware innovation platform for makers to grow inspirations into differentiating products. By working closely with technology providers of all scale, Seeed provides accessible technologies with quality, speed and supply chain knowledge. When prototypes are ready to iterate, Seeed helps productize 1 to 1,000 pcs using in-house engineering, supply chain management and agile manufacture forces. Seeed also team up with incubators, Chinese tech ecosystem, investors and distribution channels to portal Maker startups beyond.

