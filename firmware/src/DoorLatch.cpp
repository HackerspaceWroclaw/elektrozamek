#include "DoorLatch.h"

using namespace ::hswro::elektrozamek;

DoorLatch::DoorLatch(AbstractGpioPin &boltOutput, AbstractGpioPin &senseInput, PinPolarity outputPolarity, PinPolarity inputPolarity) :
    boltOuptut(boltOutput),
    senseInput(senseInput),
    outputPolarity(outputPolarity),
    inputPolarity(inputPolarity)
{
    close();
    gpioPin.setMode(AbstrGpioPin::Mode::Output);
}

bool DoorLatch::open()
{
    if(outputPolarity == PinPolarity::ActiveHigh)
        boltOutput.turnOn();
    else
        boltOutput.turnOff();

    //100ms delay;
    return isOpen();
}

void DoorLatch::close()
{
    if(outputPolarity == PinPolarity::ActiveHigh)
        boltOutput.turnOff();
    else
        boltOutput.turnOn();

    //100ms delay;
    return !isOpen();
}

bool DoorLatch::isOpen()
{
    if(outputPolarity == PinPolarity::ActiveHigh)
        return senseInput.isHigh();
    else
        return !senseInput.isHigh();
}
