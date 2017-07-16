#ifndef ABSTRACTGPIOPIN_H
#define ABSTRACTGPIOPIN_H

namespace hswro {
namespace elektrozamek {

class AbstractGpioPin
{
    enum class Mode
    {
        Input,
        InputWithPullup,
        InputWithPulldown,
        Output,
        Analog
    };
    enum class State
    {
        Low,
        High
    };

public:
    AbstractGpioPin();
    virtual void setMode(Mode mode) = 0;
    virtual void setState(State state) = 0;
    virtual bool isHigh() = 0;

    bool operator bool();
    void turnOn();
    void turnOff();
    void toggle();
    void setState(bool isHigh);
};

}}

#endif // ABSTRACTGPIOPIN_H
