BME680:
===========
![BME680](https://github.com/linux-downey/picture_repository/blob/master/BME680.png)
BME680 is an integrated environmental sensor developed specifically for mobile applications and wearables where size and low power consumption are key requirements.It also supports four kinds of numerical measurements of temperature, humidity, gas and air pressure.  

Usage:
==========
***This Bme680 version only supports IIC communication protocols.***
There are three arduino examples for different usecase.
>1. basic:This sketch is the basic example to perform measurement,the problem is that the result of gas value may be inaccurate.Because the gas measurement depends on a baseline which stored in the host,the baseline can be seen as compensation.
>2. basic_config_state:Compare to the basic,this example will store the baseline regular.Baseline will be loaded after the host restarts.This example is recommended when user wants to
>3. basic_config_state_ulp_plus:Measurement is automatic.if user wants to perform a additionnal mersurement,use a key interrupt to do this.



***user also can downloads the source code and running it on arduino IDE,More details in /examples***


statement:
==========
This software is written by downey for seeed studio and is licensed under The MIT License. Check License.txt for more information.

Contributing to this software is warmly welcomed. You can do this basically by
forking, committing modifications and then pulling requests (follow the links above
for operating guide). Adding change log and your contact into file header is encouraged.
Thanks for your contribution.

Seeed is a hardware innovation platform for makers to grow inspirations into differentiating products. By working closely with technology providers of all scale, Seeed provides accessible technologies with quality, speed and supply chain knowledge. When prototypes are ready to iterate, Seeed helps productize 1 to 1,000 pcs using in-house engineering, supply chain management and agile manufacture forces. Seeed also team up with incubators, Chinese tech ecosystem, investors and distribution channels to portal Maker startups beyond.

