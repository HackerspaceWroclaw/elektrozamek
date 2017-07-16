#include "AbstractLogger.h"

using namespace ::hswro::elektrozamek;

AbstractLogger::AbstractLogger()
{}

void AbstractLogger::debug(const char *format, ...)
{
        va_list args;
        va_start(args, format);
        formatLog(LogLevel::Debug, format, args);
        va_end(args);
}

void AbstractLogger::info(const char *format, ...)
{
        va_list args;
        va_start(args, format);
        formatLog(LogLevel::Info, format, args);
        va_end(args);
}

void AbstractLogger::warning(const char *format, ...)
{
        va_list args;
        va_start(args, format);
        formatLog(LogLevel::Warning, format, args);
        va_end(args);
}

void AbstractLogger::error(const char *format, ...)
{
        va_list args;
        va_start(args, format);
        formatLog(LogLevel::Error, format, args);
        va_end(args);
}
