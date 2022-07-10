#include "molReader.h"

#include <vector>

#include "atom.h"
#include "logger.h"
#include "twoAtomBonds.h"

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

/*
 *
 * Reads a SYS_MOLECULE file
 *
 */

[[nodiscard]] vector<molecule> molReader::MolConfReader()
{
    ifstream         molFile(defaultFileName);
    string           line;
    vector<molecule> outMolecules;

    if (molFile.is_open())
    {
        while (std::getline(molFile, line))
        {
            if (line[0] == 'M')
            {
                outMolecules.emplace_back(readSingleMol(molFile));
            }
        }
    }

    return outMolecules;
}

/*
 *
 * reads a single molecule when the main loop finds the M character
 *
 */

[[nodiscard]] molecule molReader::readSingleMol(std::ifstream& inStream)
{
    bool readOk{true};

    string name;
    string line;
    std::getline(inStream, name);
    std::getline(inStream, line);
    string numOfAtomsErr =
        "Invalid number of atoms in molecule \"" + name + "\"\n";

    size_t numOfAtoms{readlib::readSIZE_T(line, numOfAtomsErr)};
    size_t tempNum{1};

    // molecule outMolecule = molecule(name,numOfAtoms);
    vector<atom> tempAtoms(numOfAtoms);

    // get the atoms
    for (size_t i = 0; i < numOfAtoms && readOk; i++)
    {
        std::getline(inStream, line);
        if (readAtom(line, tempAtoms[i], name, i, tempNum))
        {
            size_t iTemp{i};
            for (size_t j = 1; j < tempNum; j++)
            {
                tempAtoms[++i] = tempAtoms[iTemp];
            }
        }
        else
        {
            readOk = false;
        }
    }

    // get the 2atom bonds
    std::getline(inStream, line);
    std::istringstream iss(line);
    std::string        identifer;
    std::string        numOf2ABonds;
    iss >> identifer >> numOf2ABonds;

    if (identifer != "2B")
    {
        LOGTOSCREEN("failed to find 2 atoms bond config for " + name + "\n");
        exit(EXIT_FAILURE);
    }

    std::string numOf2ABondsErr =
        "<Invalid number of atoms in molecule \"" + name + "\"\n";
    size_t numOfTwoAtomBonds =
        readlib::readSIZE_T(numOf2ABonds, numOf2ABondsErr);

    // allocate 2 bonds poitner
    std::vector<twoBonds_t> temp2Bonds(numOfTwoAtomBonds);

    //  get the 2 Atom Bonds
    for (size_t i = 0; i < numOfTwoAtomBonds && readOk; i++)
    {
        std::getline(inStream, line);
        readOk = read2ABond(line, temp2Bonds[i], name, i);
    }

    // create and return the molecule
    return molecule(name, tempAtoms, temp2Bonds);
}

/*
 *
 * reads a single atom
 *
 */

bool molReader::readAtom(const std::string& inStream,
                         atom&              inAtom,
                         const std::string& molName,
                         size_t             atomNum,
                         size_t&            inNumOfAtoms)
{
    std::istringstream iss(inStream);
    std::string        name;
    std::string        word;
    std::string        numOfAtoms;

    iss >> name;
    iss >> word;
    iss >> numOfAtoms;
    double inMass;
    logger::logFile << "name is " << name << "\n";
    logger::logFile << "word is " << word << "\n";

    std::string errText = "Argument is invalid\n"
                          "The molecule is \"" +
                          molName + "\"\n" + "Atom number is " +
                          std::to_string(atomNum) + "\n";

    inMass = readlib::readDOU(word, errText);

    inAtom = atom(name, inMass);

    if (numOfAtoms.empty())
    {
        inNumOfAtoms = 1;
    }
    else
    {
        inNumOfAtoms = readlib::readSIZE_T(numOfAtoms, errText);
    }

    return true;
}

/*
 *
 * reads the informtion to define a 2 atom bond
 *
 */

bool molReader::read2ABond(const std::string& inStream,
                           twoBonds_t&        inBond,
                           const std::string& molName,
                           size_t             bondNum)
{

    std::istringstream iss(inStream);
    std::string        bondName;
    std::string        inAtom1;
    std::string        inAtom2;
    std::string        inParam1;
    std::string        inParam2;

    std::string errText = "Argument is invalid\n"
                          "The molecule is \"" +
                          molName + "\"\n" + "Bond number is " +
                          std::to_string(bondNum) + "\n";

    iss >> bondName;
    iss >> inAtom1 >> inAtom2;
    iss >> inParam1 >> inParam2;

    // read in atoms
    size_t atom1 = readlib::readSIZE_T(inAtom1, errText);
    size_t atom2 = readlib::readSIZE_T(inAtom2, errText);

    // read in params
    double param1 = readlib::readDOU(inParam1, errText);
    double param2 = readlib::readDOU(inParam2, errText);

    // convert name to internal enum
    twoAtomBondName twoABName = twoAtomBonds::get2AtomBond(bondName);

    inBond = {
        atom1,    // first atom
        atom2,    // second atom
        param1,   // first param
        param2,   // second param
        twoABName // definition of bond
    };

    return true;
}
