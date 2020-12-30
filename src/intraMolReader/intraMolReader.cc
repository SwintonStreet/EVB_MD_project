#include "intraMolReader.h"
#include "atom.h"
#include "intraMolBonds.h"
#include "logger.h"
#include "readlib.h"
#include "stdlib.h" // for the exit statement
#include <vector>

bool intraMolReader::readIntraMolReader()
{
    std::ifstream              molFile(defaultFileName);
    std::string                line;
    std::vector<intraMolBonds> intraMolBondsVec;

    if (molFile.is_open())
    {
        while (std::getline(molFile, line))
        {
            if (line == "IM")
            {
                // outMolecules.emplace_back(readSingleMol(molFile));
            }
        }
    }
    return true;
}
