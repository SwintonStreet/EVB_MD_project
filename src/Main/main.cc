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

int main()
{
    keyWordVec kwVec;
    LOGTOSCREEN("==--START-OF-PROGRAM--==\n")

    keyWordReader::defaultReader(kwVec);

    kwVec.print(logger::getLogFile());

    keyWord test = keyWord();
    test.setKeyWord(kwVec, "KEY1");

    std::cout << "value is " << test.getInt() << std::endl;

    std::vector<molecule> defMol  = molReader::MolConfReader();
    sys                   testSys = xyzReader::readXyzFile(defMol);

    testSys.printSysPos(std::cout);
    // print out system information
    testSys.printSysPos(logger::getLogFile());

    mainLoop mL = mainLoop(kwVec, testSys);

    mL.runLoop(logger::getLogFile());

    LOGTOSCREEN("==--END-OF-PROGRAM--==\n")

    logger::getLogFile().close();

    return 0;
}
