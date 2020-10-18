// mainLoop class header

#ifndef MAINLOOP_H
#define MAINLOOP_H

#include "string"
#include "iostream"
#include "vector"
#include "sys.h"
#include "keyWordReader.h"
#include "keyWord.h"
#include "keyWordVec.h"
#include "twoBondLoop.h"
#include "systemUpdate.h"
#include "systemUpdate.h"

class mainLoop
{

    // List of mandatory internal
    // variables for mainLoop
    int        numOfLoop;
    double     timeStep;
    sys        curSys;
    keyWordVec kwVec{};
    int        iteration;

    constexpr static const char* className = "mainLoop";

    public:

    // constructor
    mainLoop(const keyWordVec& inKWV,
             const sys&        inSys);

    // sets double value
    void setDouble(double&,
                   const std::string&,
                   const bool&);

    // sets int value
    void setInt(int&,
                const std::string&,
                const bool&);

    // sets bool value
    void setBool(bool&,
                 const std::string&,
                 const bool&);

    // Run the loop
    void runLoop();

    // print out SysInformation to an ostream
    friend std::ostream& operator<<(std::ostream& os, const mainLoop& mL)
    {
        os << "-- " << mL.iteration << "\n"
           << mL.curSys;
        return os;
    }

};


#endif // MAINLOOP_H
