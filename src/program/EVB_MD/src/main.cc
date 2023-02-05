// main - the thing that runs!
#include <fstream>
#include <iostream>
#include <optional>
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

using loops::mainLoop;
using reader::keyWordReader;

constexpr static const char* className = "Main";

int main()
{
    // Init logging
    [[maybe_unused]] const logger::logger loggingContainer;

    LOGTOSCREEN("==--START-OF-PROGRAM--==\n")

    keyWordReader keyWordsReader{};

    const reader::keyWordVec keyWords{keyWordsReader.defaultReader()};

    vector<molecule> molecules{molReader::MolConfReader()};

    sys system{xyzReader::readXyzFile(molecules)};

    mainLoop mL = mainLoop(keyWords, system);

    mL.runLoop();

    LOGTOSCREEN("==--END-OF-PROGRAM--==\n")

    return 0;
}
