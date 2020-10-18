// main - the thing that runs!

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "evb_system.h"
#include "keyWordReader.h"
#include "keyWordVec.h"
#include "logger.h"
#include "mainLoop.h"
#include "molReader.h"
#include "molecule.h"
#include "xyzReader.h"

constexpr static const char* className = "Main";

int main()
{
    LOGTOSCREEN("==--START-OF-PROGRAM--==\n")

    keyWordVec kwVec;
    keyWordReader::defaultReader(kwVec);
    LOGTOSCREEN("==--VARIABLES--==\n");

    std::vector<molecule> defMol  = molReader::MolConfReader();
    sys                   testSys = xyzReader::readXyzFile(defMol);

    // print out system information
    logger::logFile << testSys;

    mainLoop mL = mainLoop(kwVec, testSys);

    mL.runLoop();

    LOGTOSCREEN("==--END-OF-PROGRAM--==\n")

    logger::logFile.close();

    return 0;
}
