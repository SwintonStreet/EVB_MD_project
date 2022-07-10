#include "xyzReader.h"

#include <sstream>

#include "logger.h"
#include "readlib.h"

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

sys xyzReader::readXyzFile(std::vector<molecule>& inMolVec)
{
    ifstream molFile(xyzReader::defaultMolFile);
    ifstream xyzFile(xyzReader::defaultXyzFile);
    string   line;
    string   temp;
    string   numOfMols;
    string   numErr;

    // inMolVec is a vector of the defined molecules
    vector<size_t> molNums(inMolVec.size());

    /*
     * reads in the number of molecules
     * in each available molecule type
     * this is the only time the molecule
     * file is used
     */
    if (molFile.is_open())
    {
        size_t i{0};
        while (std::getline(molFile, line))
        {
            if (line[0] == 'M')
            {
                std::istringstream iss(line);
                iss >> temp;
                iss >> numOfMols;
                numErr = "error getting the number of molecule of type" +
                         std::string(inMolVec[i].getName());
                molNums[i] = readlib::readSIZE_T(numOfMols, numErr);
            }
        }
    }

    // set up the system
    sys system(inMolVec.size(), molNums, inMolVec);

    if (xyzFile.is_open())
    {
        // read the first two lines of an xyz file
        // these aren't of interest
        std::getline(xyzFile, line);
        std::getline(xyzFile, line);

        // get the molecules list
        vector<vector<molecule>>& inMols = system.getMols();

        /*
         * j is the index for the three depth array
         * j[0] is the molecule type
         * j[1] is the molcule number of type j[0]
         * j[2] is the atom number for molecule j[1] of molecule type j[0]
         *
         * k is the over-all-number used for debuging
         */
        size_t molType{0};
        size_t molNum{0};
        size_t atomNum{0};
        size_t count{0};

        while (std::getline(xyzFile, line))
        {
            if (line.length() == 0)
            {
                // if the line is empty skip the line!
                continue;
            }

            // make sure there aren't to many atoms!
            if (molType >= inMols.size())
            {
                LOGTOSCREEN("To many atoms in the XYZ file");
                exit(EXIT_FAILURE);
            }

            // read atom
            atom& tmpAtom = inMols[molType][molNum].getAtom(atomNum);

            readAtom(line, tmpAtom, ++count);

            // increment the atom number
            atomNum++;

            // if we run out of atoms increment the molcule number
            if (atomNum >= inMols[molType][molNum].getSize())
            {
                molNum++;
                atomNum = 0;
            }

            // if we run out of molecules then increment the molecule type
            // number
            if (molNum >= inMols[molType].size())
            {
                molType++;
                molNum  = 0;
                atomNum = 0;
            }
        }
    }

    // print out system information
    logger::logFile << system;

    return system;
}

void xyzReader::readAtom(const string& line, atom& inAtom, size_t k)
{
    istringstream iss(line);
    string        x;
    string        y;
    string        z;

    // ignore the atom name
    iss >> x;
    // read in the xyz values
    iss >> x >> y >> z;

    std::string errText = "Failed to read atom " + std::to_string(k) +
                          " position from the xyz file";

    inAtom.setPos({readlib::readDOU(x, errText),
                   readlib::readDOU(y, errText),
                   readlib::readDOU(z, errText)});
}
