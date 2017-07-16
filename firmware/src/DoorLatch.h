#ifndef DOORLATCH_H
#define DOORLATCH_H

#include "AbstractGpioPin.h"

namespace hswro {
namespace elektrozamek {

class DoorLatch
{
    enum class PinPolarity
    {
        ActiveHigh,
        ActiveLow
    };
public:
    DoorLatch(AbstractGpioPin &boltOutput, AbstractGpioPin &senseInput, PinPolarity outputPolarity, PinPolarity inputPolarity);

    bool open();
    bool close();
    bool isOpen();

private:
    AbstractGpioPin& boltOutput, senseInput;
    PinPolarity outputPolarity, inputPolarity;
};

}}

#endif // DOORLATCH_H
