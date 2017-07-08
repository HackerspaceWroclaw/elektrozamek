#ifndef GPIOPIN_H
#define GPIOPIN_H


class GpioPin
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
    explicit GpioPin(int ID);
    void setMode(Mode mode);
    bool isHigh();
    void turnOn();
    void turnOff();
    void setState(bool isHigh);
    void setState(State state);
};

#endif // GPIOPIN_H
