// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_SGP40"

//Include C++ libraries
#include <Adafruit_SGP40.h>

node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_SGP40*;
    }

    // Keep Adafruit_SGP30 object in state
    Adafruit_SGP30 sensor = Adafruit_SGP40();


    void evaluate(Context ctx) {
        emitValue<output_DEV>(ctx, &sensor);
    }
}
