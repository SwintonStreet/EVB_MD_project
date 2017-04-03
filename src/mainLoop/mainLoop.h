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
    int                  numOfLoop;
    double               timeStep;
    sys                  curSys;
    keyWordVec           kwVec;

    public:

    // constructor
    mainLoop(keyWordVec& inKWV,
             sys&        inSys);

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


    void runLoop(std::ostream& = std::cout);
};


#endif // MAINLOOP_H
