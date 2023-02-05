#include "mainLoop.h"

#include <memory>
#include <string>

#include "keyWord.h"
#include "keyWordVec.h"
#include "logger.h"

using reader::keyWord;
using reader::keyWordVec;

namespace loops
{

mainLoop::mainLoop(keyWordVec inKWV, sys inSys) :
    curSys_(std::move(inSys)), kwVec_{std::move(inKWV)}
{
    // extract variables
    setInt(numOfLoop_, "NUM_ITER", true);
    setInt(printEvery_, "PRINT_EVERY", true);
    setDouble(timeStep_, "TIME_STEP", true);

    // print output
    LOGTOSCREEN("numOfLoop: " + std::to_string(numOfLoop_))
}

void mainLoop::runLoop()
{
    for (; iteration_ <= numOfLoop_; ++iteration_)
    {
        // update energy and forces
        systemUpdate::sysUpdate(curSys_, timeStep_);

        // print system information
        if ((iteration_ % printEvery_) == 0)
        {
            logger::logFile << *this;
        }
    }
}

void mainLoop::setInt(int& val, const std::string& name, bool mandatory)
{
    keyWord dummy = keyWord::getKeyWord(kwVec_, name, mandatory);
    val           = dummy.getInt();
}

void mainLoop::setDouble(double& val, const std::string& name, bool mandatory)
{
    keyWord dummy = keyWord::getKeyWord(kwVec_, name, mandatory);
    val           = dummy.getDou();
}

void mainLoop::setBool(bool& val, const std::string& name, bool mandatory)
{
    keyWord dummy = keyWord::getKeyWord(kwVec_, name, mandatory);
    val           = dummy.getBoo();
}

} // namespace loops
