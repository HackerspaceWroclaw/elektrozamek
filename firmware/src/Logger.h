#ifndef LOGGER_H
#define LOGGER_H

namespace hswro {
namespace elektrozamek {

class Logger
{
public:
    Logger();

    void debug(const char* format, ...);
    void info(const char* format, ...);
    void warning(const char* format, ...);
    void error(const char* format, ...);
};

}}

#endif // LOGGER_H
