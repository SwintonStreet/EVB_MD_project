// main - the thing that runs!
#include <fstream>
#include <iostream>
#include <vector>

#include "evb_system.h"
#include "keyWordReader.h"
#include "keyWordVec.h"
#include "logger.h"
#include "mainLoop.h"
#include "molReader.h"
#include "molecule.h"
#include "xyzReader.h"

using std::vector;

constexpr static const char* className = "Main";

int main()
{
    LOGTOSCREEN("==--START-OF-PROGRAM--==\n")

    keyWordVec kwVec;
    keyWordReader::defaultReader(kwVec);

    vector<molecule> defMol{molReader::MolConfReader()};
    sys              testSys{xyzReader::readXyzFile(defMol)};

    mainLoop mL = mainLoop(kwVec, testSys);

    mL.runLoop();

    LOGTOSCREEN("==--END-OF-PROGRAM--==\n")

    logger::logFile.close();
    logger::paramFile.close();

    return 0;
}
