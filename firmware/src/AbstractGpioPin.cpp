#include "AbstractGpioPin.h"

using namespace ::hswro::elektrozamek;

AbstractGpioPin::AbstractGpioPin()
{}

bool AbstractGpioPin::operator bool()
{
     return isHigh();
}

void AbstractGpioPin::turnOn()
{
    setState(State::High);
}

void AbstractGpioPin::turnOff()
{
    setState(State::Low);
}

void AbstractGpioPin::toggle()
{
   if(isHigh())
       turnOff();
   else
       turnOn();
}

void AbstractGpioPin::setState(bool isHigh)
{
        if(isHigh)
            turnOn();
        else
            turnOff();
}
