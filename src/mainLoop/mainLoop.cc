
#include "mainLoop.h"

mainLoop::mainLoop(keyWordVec& inKWV, sys& inSys) : curSys(inSys)
{
    // set up keyWords vector
    kwVec = inKWV;

    // extract variables
    setInt(numOfLoop, "NUM_ITER", true);
    setDouble(timeStep, "TIME_STEP", true);
}

void mainLoop::runLoop(std::ostream& inStream)
{
    for (int i = 0; i <= numOfLoop; i++)
    {
        // update energy and forces
        systemUpdate::sysUpdate(curSys, timeStep);

        curSys.printSysPos(inStream);
        inStream << "-- " << i << "\n";
    }
}

void mainLoop::setInt(int&               inInt,
                      const std::string& inName,
                      const bool&        mandatory)
{
    keyWord dummy;
    dummy.setKeyWord(kwVec, inName, mandatory);
    inInt = dummy.getInt();
}

void mainLoop::setDouble(double&            inDouble,
                         const std::string& inName,
                         const bool&        mandatory)
{
    keyWord dummy;
    dummy.setKeyWord(kwVec, inName, mandatory);
    inDouble = dummy.getDou();
}

void mainLoop::setBool(bool&              inBool,
                       const std::string& inName,
                       const bool&        mandatory)
{
    keyWord dummy;
    dummy.setKeyWord(kwVec, inName, mandatory);
    inBool = dummy.getBoo();
}
