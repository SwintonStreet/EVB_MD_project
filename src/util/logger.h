// Logger class header

#ifndef LOGTOFILE
#define LOGTOFILE(x) logger::logToFile( className, __FUNCTION__, x);
#endif

#ifndef LOGTOSCREEN
#define LOGTOSCREEN(x) logger::logToScreen(x);
#endif

#ifndef LOGGER_H
#define LOGGER_H

#include<string>
#include<fstream>
#include<iostream>

namespace logger
{

    // inline is needed here so that the global function
    // is not defined twice
    inline void logToStream(std::ostream& o,
                            std::string   className,
                            std::string   funcName,
                            std::string   text)
    {
        o << "class name:    " << className << '\n'
          << "function name: " << funcName  << '\n'
          << text;
    }

    inline std::ofstream& getLogFile()
    {
        static std::ofstream logFile("Run.output");
        return logFile;
    }

    inline void logToFile(std::string className,
                          std::string funcName,
                          std::string text)
    {
        logger::logToStream(logger::getLogFile(), className, funcName, text);
    }

    inline void logToScreen(std::string text)
    {
        std::cout << text;
    }
}

#endif // LOGGER_H
