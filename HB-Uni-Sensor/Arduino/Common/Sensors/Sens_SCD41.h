#pragma once
#include <Wire.h>
#include <Sensors.h>
#include <SparkFun_SCD4x_Arduino_Library.h>

namespace as {

class Sens_SCD41 : public Sensor {
    SCD4x    _scd41;
    uint16_t _co2, _humidity10;
    int16_t _temperature10;

public:
    Sens_SCD41()
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
            if (_scd41.begin()) {
                _present = true;
                DPRINTLN(F("SCD4x found"));

                _scd41.setSensorAltitude(255);
                _scd41.stopPeriodicMeasurement();
                _scd41.startLowPowerPeriodicMeasurement();

                return true;
            }
            delay(100);
            i--;
        }
        DPRINTLN(F("Error: SCD4x not found"));
        return false;
    }

    bool measure()
    {
        if (_present) {
            if (_scd41.getDataReadyStatus()) {
                _co2           = _scd41.getCO2();
                _temperature10 = (int16_t)(_scd41.getTemperature() * 10.0f);
                _humidity10    = (uint16_t)(_scd41.getHumidity() * 10.0f);
#ifndef NDEBUG
                DPRINT(F("SCD41 CO2: "));
                DDECLN((int)_co2);
#endif
            } else {
#ifndef NDEBUG
                DPRINT(F("No new SCD41 data"));
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