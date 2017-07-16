#ifndef ISERIALPORT_H
#define ISERIALPORT_H

#include <stddef.h>

namespace hswro {
namespace elektrozamek {

class ISerialPort
{
public:
    enum Parity
    {
        None,
        Odd,
        Even
    };

    enum StopBits
    {
        One,
        OneAndHalf,
        Two
    };

    virtual ~ISerialPort {};
    virtual size_t read(char* output, size_t size) = 0;
    virtual size_t write(char* output, size_t size) = 0;
    virtual void flush() = 0;

    virtual void setConfig(int baud, Parity parity, StopBits stopBits) = 0;
    virtual void setBaud(int baud) = 0;
    virtual void setParity(Parity parity) = 0;
    virtual void setStopBits(StopBits stopBits) = 0;
};

}}

#endif // ISERIALPORT_H
