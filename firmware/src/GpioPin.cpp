#include "GpioPin.h"

GpioPin::GpioPin(int ID)
{

}

void GpioPin::setMode(GpioPin::Mode mode)
{

}

bool GpioPin::isHigh()
{

}

void GpioPin::turnOn()
{
    setState(State::High);
}

void GpioPin::turnOff()
{
    setState(State::Low);
}

void GpioPin::setState(bool isHigh)
{
        if(isHigh)
            setState(State::High);
        else
            setState(State::Low);
}

void GpioPin::setState(GpioPin::State state)
{

}
