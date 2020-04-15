#include<string>
#include<fstream>
#include<iostream>

#ifndef LOGTOFILE
#define LOGTOFILE(x) logger::logToFile( className, __FUNCTION__, x);
#endif

#ifndef LOGTOSCREEN
#define LOGTOSCREEN(x) logger::logToScreen(x);
#endif

namespace logger
{

    void logToStream(std::ostream& o,
                     std::string   className,
                     std::string   funcName,
                     std::string   text)
    {
        o << "class name:    " << className << '\n'
          << "function name: " << funcName  << '\n'
          << text;
    }

    std::ofstream& getLogFile()
    {
        static std::ofstream logFile("Run2");
        return logFile;
    }

    void logToFile(std::string className,
                   std::string funcName,
                   std::string text)
    {
        logger::logToStream(logger::getLogFile(), className, funcName, text);
    }

    void logToScreen(std::string text)
    {
        std::cout << text;
    }
}
