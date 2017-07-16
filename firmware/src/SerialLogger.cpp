#include "SerialLogger.h"

using namespace ::hswro::elektrozamek;

SerialLogger::SerialLogger(ISerialPort& serialPort):
    serialPort(serialPort)
{
}

void SerialLogger::formatLog(hswro::elektrozamek::AbstractLogger::LogLevel logLevel, const char *format, va_list args)
{
        char newFormat[128];
        const char *logLevelStrings[] = { "DBG/", "INF/", "WRN/", "ERR/" };
        /* This is the least crappy solution I came up with at 23:40 after a beer.
         * sstream is not available on this platform.
         * CAN YOU SPOT THE BUG? */
        snprintf(newFormat, sizeof(newFormat), "%s%s\n", logLevelStrings[logLevel], format);

        char buffer[256];
        size_t actualSize = vsnprintf(buffer, sizeof(buffer), newFormat, args);
        serialPort.write(buffer, actualSize);
}
