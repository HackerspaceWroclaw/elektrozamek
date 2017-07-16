#ifndef GPIOPIN_H
#define GPIOPIN_H

namespace hswro {
namespace elektrozamek {

class IGpioPin
{
    enum class Mode
    {
        Input,
        InputWithPullup,
        InputWithPulldown,
        Output
    };
    enum class State
    {
        Low,
        High
    };

public:
    explicit IGpioPin(int ID);
    void setMode(Mode mode);
    bool isHigh();
    void turnOn();
    void turnOff();
    void toggle();
    void setState(bool isHigh);
    void setState(State state);
};

}}

#endif // GPIOPIN_H
