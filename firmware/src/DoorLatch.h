#ifndef DOORLATCH_H
#define DOORLATCH_H

#include "GpioPin.h"

namespace hswro {
namespace elektrozamek {

class DoorLatch
{
    enum class ActiveState
    {
        High,
        Low
    };
public:
    DoorLatch(GpioPin gpioPin, ActiveState activeState);

    void open();
    void close();

private:
    GpioPin& gpioPin;
    ActiveState activeState;
};
}}

#endif // DOORLATCH_H
