#ifndef SERIALLOGGER_H
#define SERIALLOGGER_H

#include "AbstractLogger.h"
#include "ISerialPort.h"

namespace  hswro {
namespace elektrozamek {

class SerialLogger : public AbstractLogger
{
public:
    explicit SerialLogger(ISerialPort& serialPort);
    virtual void formatLog(LogLevel logLevel, const char* format, va_list args);
    virtual void flush();

private:
    ISerialPort& serialPort;
};

}}

#endif // SERIALLOGGER_H
