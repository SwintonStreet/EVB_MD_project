#include "xyzReader.h"
#include "logger.h"

sys xyzReader::readXyzFile(std::vector<molecule>& inMolVec)
{
    std::ifstream molFile(xyzReader::defaultMolFile);
    std::ifstream xyzFile(xyzReader::defaultXyzFile);
    std::string   line;
    std::string   temp;
    std::string   numOfMols;
    std::string   numErr;

    // inMolVec is a vector of the defined molecules
    std::vector<int> molNums(inMolVec.size());
    int              totalNumMolecules = 0;

    /*
     * reads in the number of molecules
     * in each available molecule type
     * this is the only time the molecule
     * file is used
     */
    if (molFile.is_open())
    {
        int i{0};
        while (std::getline(molFile, line))
        {
            if (line[0] == 'M')
            {
                std::istringstream iss(line);
                iss >> temp;
                iss >> numOfMols;
                numErr = "error getting the number of molecule of type" +
                         std::string(inMolVec[i].getName());
                molNums[i] = readlib::readINT(numOfMols, numErr);
                totalNumMolecules += molNums[i++];
            }
        }
    }

    // set up the system
    sys tmp(inMolVec.size(), molNums, inMolVec);

    if (xyzFile.is_open())
    {
        // read the first two lines of an xyz file
        // these aren't of interest
        std::getline(xyzFile, line);
        std::getline(xyzFile, line);

        // get the molecules list
        std::vector<std::vector<molecule>>& inMols = tmp.getMols();

        /*
         * j is the index for the three depth array
         * j[0] is the molecule type
         * j[1] is the molcule number of type j[0]
         * j[2] is the atom number for molecule j[1] of molecule type j[0]
         *
         * k is the over-all-number used for debuging
         */
        int j[3] = {0, 0, 0};
        int k    = 0;
        while (std::getline(xyzFile, line))
        {
            if (line.length() == 0)
            {
                // if the line is empty skip the line!
                continue;
            }

            // make sure there aren't to many atoms!
            if (j[0] >= static_cast<int>(inMols.size()))
            {
                LOGTOSCREEN("To many atoms in the XYZ file");
                exit(EXIT_FAILURE);
            }

            // read atom
            atom& tmpAtom = inMols[j[0]][j[1]].getAtom(j[2]);

            readAtom(line, tmpAtom, ++k);

            // increment the atom number
            j[2]++;

            // if we run out of atoms increment the molcule number
            if (j[2] >= inMols[j[0]][j[1]].getSize())
            {
                j[1]++;
                j[2] = 0;
            }

            // if we run out of molecules then increment the molecule type
            // number
            if (j[1] >= static_cast<int>(inMols[j[0]].size()))
            {
                j[0]++;
                j[1] = 0;
                j[2] = 0;
            }
        }
    }

    // print out system information
    logger::logFile << tmp;

    return tmp;
}

void xyzReader::readAtom(const std::string& inLine, atom& inAtom, int k)
{
    std::istringstream iss(inLine);
    std::string        x;
    std::string        y;
    std::string        z;

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
