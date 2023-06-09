
//---------------------------------------------------------
// Sens_DIGINPUT
// 2019-03-03 Tom Major (Creative Commons)
// https://creativecommons.org/licenses/by-nc-sa/3.0/
// You are free to Share & Adapt under the following terms:
// Give Credit, NonCommercial, ShareAlike
// +++
// AskSin++ 2016-10-31 papa Creative Commons
// HB-UNI-Sen-PRESS-SC 2018-05-14 jp112sdl Creative Commons
//---------------------------------------------------------

#ifndef _SENS_ANAINPUT_H_
#define _SENS_ANAINPUT_H_

#include <Sensors.h>

namespace as {

class Sens_ANAINPUT : public Sensor {

    uint8_t _pin;
    uint8_t _power;

public:
    Sens_ANAINPUT() {}

    void init(uint8_t inputPin, uint8_t powerPin)
    {
        _pin = inputPin;
        pinMode(_pin, INPUT);
	
        _power = powerPin;
	pinMode(_power, OUTPUT);
	digitalWrite(_power, HIGH);
    }

    uint16_t pinState() { 
    	digitalWrite(_power, LOW);
    	delay(10);
    	uint16_t value = analogRead(_pin); 
    	digitalWrite(_power, HIGH);
    	return value;
    }
};

}

#endif
