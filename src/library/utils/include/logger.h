// Logger class header

#ifndef LOGTOFILE
#define LOGTOFILE(x) logger::logToFile(className, __FUNCTION__, x);
#endif

#ifndef TEXTTOSCREEN
#define TEXTTOSCREEN(x) logger::logToScreen(x);
#endif

#ifndef LOGTOSCREEN
#define LOGTOSCREEN(x) logger::logToScreen(className, __FUNCTION__, x);
#endif

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <string>

namespace logger
{
static std::ofstream logFile("Run.output");
static std::ofstream paramFile("Run.params");

// inline is needed here so that the global function
// is not defined twice
inline void logToStream(std::ostream&    o,
                        std::string_view className,
                        std::string_view funcName,
                        std::string_view text)
{
    o << '\n'
      << "class name:    " << className << '\n'
      << "function name: " << funcName << '\n'
      << text << '\n';
}

inline void logToFile(std::string_view className,
                      std::string_view funcName,
                      std::string_view text)
{
    logger::logToStream(logger::logFile, className, funcName, text);
}

inline void logToParam(std::string_view className,
                       std::string_view funcName,
                       std::string_view text)
{
    logger::logToStream(logger::paramFile, className, funcName, text);
}

inline void logToScreen(std::string text) { std::cout << text; }

inline void logToScreen(std::string_view className,
                        std::string_view funcName,
                        std::string_view text)
{
    logger::logToStream(std::cout, className, funcName, text);
}
} // namespace logger

#endif // LOGGER_H
