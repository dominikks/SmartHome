#pragma once
#include <Wire.h>
#include <Sensors.h>
#include <SparkFun_SCD30_Arduino_Library.h>

namespace as {

class Sens_SCD30 : public Sensor {
    SCD30    _scd30;
    uint16_t _co2, _humidity10;
    int16_t _temperature10;

public:
    Sens_SCD30()
        : _co2(0)
        , _humidity10(0)
        , _temperature10(0)
    {
    }

    bool init()
    {
        Wire.begin();

        uint8_t i = 10;
        while (i > 0) {
            if (_scd30.begin(true)) {
                _present = true;
                DPRINTLN(F("SCD30 found"));

                _scd30.setMeasurementInterval(40);
                _scd30.setAltitudeCompensation(255);

                return true;
            }
            delay(100);
            i--;
        }
        DPRINTLN(F("Error: SCD30 not found"));
        return false;
    }

    bool measure()
    {
        if (_present) {
            if (_scd30.dataAvailable()) {
                _co2           = _scd30.getCO2();
                _temperature10 = (int16_t)(_scd30.getTemperature() * 10.0f);
                _humidity10    = (uint16_t)(_scd30.getHumidity() * 10.0f);
#ifndef NDEBUG
                DPRINT(F("SCD30 CO2: "));
                DDECLN((int)_co2);
#endif
            } else {
#ifndef NDEBUG
                DPRINT(F("No new SCD30 data"));
#endif
            }

            return true;
        }
        return false;
    }

    uint16_t co2()
    {
        return _co2;
    }
    int16_t temperature()
    {
        return _temperature10;
    }
    uint16_t humidity()
    {
        return _humidity10;
    }
};

}