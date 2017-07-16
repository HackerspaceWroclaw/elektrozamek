#ifndef ABSTRACTLOGGER_H
#define ABSTRACTLOGGER_H

#include <stdarg.h>
namespace hswro {
namespace elektrozamek {

class AbstractLogger
{
public:
    AbstractLogger();

    void debug(const char* format, ...);
    void info(const char* format, ...);
    void warning(const char* format, ...);
    void error(const char* format, ...);
    void flush();

protected:
    enum class LogLevel
    {
        Debug,
        Info,
        Warning,
        Error
    };
    virtual void formatLog(LogLevel level, const char* format, va_list args) = 0;
};

}}

#endif // ABSTRACTLOGGER_H
