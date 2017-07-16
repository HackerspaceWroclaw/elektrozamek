#ifndef ISPIDRIVER_H
#define ISPIDRIVER_H

#include <stddef.h>

namespace hswro {
namespace elektrozamek {

typedef int TClockFrequencyKhz;

class ISpiDriver
{
    virtual size_t read(char* buffer, size_t size) = 0;
    virtual size_t write(const char* buffer, size_t size) = 0;
    virtual void setClockFrequency(TClockFrequencyKhz frequency);
};

}}

#endif // ISPIDRIVER_H
