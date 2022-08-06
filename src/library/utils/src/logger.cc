#include "logger.h"

#include <fstream>

namespace logger
{

loggerContainer::~loggerContainer()
{
    logFile.close();
    paramFile.close();
}

} // namespace logger
