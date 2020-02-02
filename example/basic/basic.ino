#include "bsec.h"

// Helper functions declarations
void checkIaqSensorStatus(void);
void errLeds(void);

// Create an object of the class Bsec
Bsec iaqSensor;

String output;

// Entry point for the example
void setup(void) {
    Serial.begin(115200);
    delay(100);
    Serial.println("start");
    iaqSensor.begin(BME680_I2C_ADDR_PRIMARY, Wire);
    output = "\nBSEC library version " + String(iaqSensor.version.major) + "." + String(
                 iaqSensor.version.minor) + "." + String(iaqSensor.version.major_bugfix) + "." + String(iaqSensor.version.minor_bugfix);
    Serial.println(output);
    checkIaqSensorStatus();

    bsec_virtual_sensor_t sensorList[7] = {
        BSEC_OUTPUT_RAW_TEMPERATURE,
        BSEC_OUTPUT_RAW_PRESSURE,
        BSEC_OUTPUT_RAW_HUMIDITY,
        BSEC_OUTPUT_RAW_GAS,
        BSEC_OUTPUT_IAQ_ESTIMATE,
        BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE,
        BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY,
    };

    iaqSensor.updateSubscription(sensorList, 7, BSEC_SAMPLE_RATE_LP);
    checkIaqSensorStatus();

    // Print the header
    output = "Timestamp [ms], raw temperature [°C], pressure [hPa], raw relative humidity [%], gas [Ohm], IAQ, IAQ accuracy, temperature [°C], relative humidity [%]";
    Serial.println(output);
}

// Function that is looped forever
void loop(void) {
    if (iaqSensor.run()) { // If new data is available
        output = "Timestamp[ms]=";
        output += String(millis());
        output += '\n';
        //output += ", " + String(iaqSensor.rawTemperature);
        output += "Pressure[hPa]=";
        output +=  String(iaqSensor.pressure);
        output += '\n';

        output += "IAQ=";
        output += String(iaqSensor.iaqEstimate);
        output += '\n';

        output += "IAQAccuracy=";
        output += String(iaqSensor.iaqAccuracy);
        output += '\n';

        output += "temperature=";
        output += String(iaqSensor.temperature);
        output += '\n';

        output += "humidity=";
        output += String(iaqSensor.humidity);
        output += '\n';

        Serial.println(output);
        Serial.println(' ');
        Serial.println(' ');
    } else {
        checkIaqSensorStatus();
    }
}

// Helper function definitions
void checkIaqSensorStatus(void) {
    if (iaqSensor.status != BSEC_OK) {
        if (iaqSensor.status < BSEC_OK) {
            output = "BSEC error code : " + String(iaqSensor.status);
            Serial.println(output);
            for (;;) {
                errLeds();    /* Halt in case of failure */
            }
        } else {
            output = "BSEC warning code : " + String(iaqSensor.status);
            Serial.println(output);
        }
    }

    if (iaqSensor.bme680Status != BME680_OK) {
        if (iaqSensor.bme680Status < BME680_OK) {
            output = "BME680 error code : " + String(iaqSensor.bme680Status);
            Serial.println(output);
            for (;;) {
                errLeds();    /* Halt in case of failure */
            }
        } else {
            output = "BME680 warning code : " + String(iaqSensor.bme680Status);
            Serial.println(output);
        }
    }
}

void errLeds(void) {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}