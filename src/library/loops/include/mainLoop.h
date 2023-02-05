// mainLoop class header
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "keyWord.h"
#include "keyWordReader.h"
#include "keyWordVec.h"
#include "sys.h"
#include "systemUpdate.h"
#include "twoBondLoop.h"

namespace loops
{

class mainLoop
{
  public:
    // constructor
    mainLoop(reader::keyWordVec inKWV, sys inSys);

    // sets double value
    void setDouble(double& val, const std::string& name, bool mandatory);

    // sets int value
    void setInt(int& val, const std::string& name, bool mandatory);

    // sets bool value
    void setBool(bool& val, const std::string& name, bool mandatory);

    // Run the loop
    void runLoop();

    // print out SysInformation to an ostream
    friend std::ostream& operator<<(std::ostream& os, const mainLoop& mL)
    {
        os << "-- Iteration " << mL.iteration_ << "\n" << mL.curSys_;
        return os;
    }

  private:
    // List of mandatory internal
    // variables for mainLoop
    int                numOfLoop_{0};
    int                printEvery_{1};
    int                iteration_{0};
    double             timeStep_{1};
    sys                curSys_;
    reader::keyWordVec kwVec_;

    constexpr static const char* className = "mainLoop";
};

} // namespace loops
