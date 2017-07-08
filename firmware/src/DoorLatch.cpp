#include "DoorLatch.h"

using namespace ::hswro::elektrozamek;

DoorLatch::DoorLatch(GpioPin gpioPin, ActiveState activeState):
    gpioPin(gpioPin),
    activeState(activeState)
{
    close();
    gpioPin.setMode(GpioPin::Mode::Output);
}

void DoorLatch::open()
{
    if(activeState == ActiveState::High)
        gpioPin.turnOn();
    else
        gpioPin.turnOff();
}

void DoorLatch::close()
{
    if(activeState == ActiveState::High)
        gpioPin.turnOff();
    else
        gpioPin.turnOn();
}
