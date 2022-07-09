#include "mainLoop.h"

#include "logger.h"

mainLoop::mainLoop(const keyWordVec& inKWV, const sys& inSys) :
    curSys(inSys), kwVec{inKWV}
{
    // extract variables
    setInt(numOfLoop, "NUM_ITER", true);
    setInt(printEvery, "PRINT_EVERY", true);
    setDouble(timeStep, "TIME_STEP", true);

    // print output
    LOGTOSCREEN("numOfLoop: " + std::to_string(numOfLoop))
}

void mainLoop::runLoop()
{
    for (; iteration <= numOfLoop; ++iteration)
    {
        // update energy and forces
        systemUpdate::sysUpdate(curSys, timeStep);

        // print system information
        if ((iteration % printEvery) == 0)
        {
            logger::logFile << *this;
        }
    }
}

void mainLoop::setInt(int&               inInt,
                      const std::string& inName,
                      const bool&        mandatory)
{
    keyWord dummy = keyWord::getKeyWord(kwVec, inName, mandatory);
    inInt         = dummy.getInt();
}

void mainLoop::setDouble(double&            inDouble,
                         const std::string& inName,
                         const bool&        mandatory)
{
    keyWord dummy = keyWord::getKeyWord(kwVec, inName, mandatory);
    inDouble      = dummy.getDou();
}

void mainLoop::setBool(bool&              inBool,
                       const std::string& inName,
                       const bool&        mandatory)
{
    keyWord dummy = keyWord::getKeyWord(kwVec, inName, mandatory);
    inBool        = dummy.getBoo();
}
