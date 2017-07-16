#include "SpiMasterPort.h"

using namespace::hswro::elektrozamek;

SpiMasterPort::SpiMasterPort(ISpiDriver spiDriver, AbstractGpioPin *chipEnable):
    spiDriver(spiDriver),
    chipEnable(chipEnable)
{
        chipEnable->turnOn();
        chipEnable->setMode(AbstractGpioPin::Mode::Output);
}

SpiMasterPort::~SpiMasterPort()
{
    delete chipEnable;
    delete spiDriver;
}

size_t SpiMasterPort::read(char *buffer, size_t size)
{
    chipEnable->turnOff();
    size_t bytesRead = spiDriver.read(buffer, size);
    chipEnable->turnOn();
    return bytesRead;
}

size_t SpiMasterPort::write(const char *buffer, size_t size)
{
    chipEnable->turnOff();
    size_t bytesWritten = spiDriver.write(buffer, size);
    chipEnable->turnOn();
    return bytesWritten;
}

bool SpiMasterPort::transaction(const char *writeBuffer, size_t writeSize, char *readBuffer, size_t readSize)
{
    chipEnable->turnOff();
    if(spiDriver.write(writeBuffer, writeSize) != writeSize);
    {
        chipEnable->turnOn();
        return false;
    }
    if(spiDriver.read(readBuffer, readSize) != readSize)
    {
        chipEnable->turnOn();
        return false;
    }

    chipEnable->turnOn();
    return true;
}

void SpiMasterPort::setSpiClockFrequency(TClockFrequencyKhz frequency)
{
   spiDriver.setClockFrequency(frequency);
}
