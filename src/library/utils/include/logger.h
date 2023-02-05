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

class logger
{
  public:
    logger() = default;

    static std::ofstream& getLogFile()
    {
        static std::ofstream logFile{"Run.output"};
        return logFile;
    }

    static std::ofstream& getParamFile()
    {
        static std::ofstream logFile{"Run.param"};
        return logFile;
    }
};

// inline is needed here so that the global function
// is not defined twice
template <typename T>
inline void logToStream(std::ostream&    o,
                        std::string_view className,
                        std::string_view funcName,
                        const T&         obj)
{
    o << '\n'
      << "class name:    " << className << '\n'
      << "function name: " << funcName << '\n'
      << obj << std::endl;
}

template <typename T>
inline void
logToFile(std::string_view className, std::string_view funcName, const T& obj)
{
    logToStream(logger::getLogFile(), className, funcName, obj);
}

template <typename T>
inline void
logToParam(std::string_view className, std::string_view funcName, const T& obj)
{
    logToStream(logger::getParamFile(), className, funcName, obj);
}

inline void logToScreen(std::string_view text) { std::cout << text; }

inline void logToScreen(std::string_view className,
                        std::string_view funcName,
                        std::string_view text)
{
    logToStream(std::cout, className, funcName, text);
}

} // namespace logger

#endif // LOGGER_H
