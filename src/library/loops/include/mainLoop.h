// mainLoop class header
#ifndef MAINLOOP_H
#define MAINLOOP_H

#include <iostream>
#include <string>
#include <vector>

#include "keyWord.h"
#include "keyWordReader.h"
#include "keyWordVec.h"
#include "sys.h"
#include "systemUpdate.h"
#include "twoBondLoop.h"

class mainLoop
{

    // List of mandatory internal
    // variables for mainLoop
    int        numOfLoop{0};
    int        printEvery{1};
    int        iteration{0};
    double     timeStep{1};
    sys        curSys;
    keyWordVec kwVec{};

    constexpr static const char* className = "mainLoop";

  public:
    // constructor
    mainLoop(const keyWordVec& inKWV, const sys& inSys);

    // sets double value
    void setDouble(double&, const std::string&, const bool&);

    // sets int value
    void setInt(int&, const std::string&, const bool&);

    // sets bool value
    void setBool(bool&, const std::string&, const bool&);

    // Run the loop
    void runLoop();

    // print out SysInformation to an ostream
    friend std::ostream& operator<<(std::ostream& os, const mainLoop& mL)
    {
        os << "-- Iteration " << mL.iteration << "\n" << mL.curSys;
        return os;
    }
};

#endif // MAINLOOP_H
