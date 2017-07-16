#ifndef SPIMASTERPORT_H
#define SPIMASTERPORT_H

#include <stddef.h>
#include <AbstractGpioPin.h>
#include <ISpiDriver.h>

namespace hswro {
namespace elektrozamek {

class SpiMasterPort
{
public:
    SpiMasterPort(ISpiDriver* spiDriver, AbstractGpioPin* AbstractGpioPin);
    ~SpiMasterPort();

    size_t read(char* buffer, size_t size);
    size_t write(const char* buffer, size_t size);
    bool transaction(const char* writeBuffer, size_t writeSize, char* readBuffer, size_t readSize);

    void setSpiClockFrequency(TClockFrequencyKhz frequency);


    AbstractGpioPin* chipEnable;
    ISpiDriver spiDriver;
};

}}

#endif // SPIMASTERPORT_H
