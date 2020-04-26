#include "molReader.h"
#include "atom.h"
#include "twoAtomBonds.h"
#include <vector>

/*
 *
 * Reads a SYS_MOLECULE file
 *
 */

[[nodiscard]] std::vector<molecule> molReader::MolConfReader() const
{
    std::ifstream         molFile(defaultFileName);
    std::string           line;
    std::vector<molecule> outMolecules;

    std::cout << "Got here\n";

    if (molFile.is_open())
    {
        while (std::getline(molFile, line))
        {
            if (line[0] == 'M')
            {
                outMolecules.push_back(readSingleMol(molFile));
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

[[nodiscard]] molecule molReader::readSingleMol(std::ifstream& inStream) const
{
    bool        readOk = true;
    std::string name, line;
    std::getline(inStream, name);
    std::getline(inStream, line);
    std::string numOfAtomsErr =
        "Invalid number of atoms in molecule \"" + name + "\"\n";
    int numOfAtoms = readlib::readINT(line, numOfAtomsErr);
    int tempNum    = 1;

    // molecule outMolecule = molecule(name,numOfAtoms);
    std::vector<atom> tempAtoms(numOfAtoms);

    // get the atoms
    for (int i = 0; i < numOfAtoms && readOk; i++)
    {
        std::getline(inStream, line);
        std::cout << line << "--" << i << '\n';
        readOk    = readAtom(line, tempAtoms[i], name, i, tempNum);
        int iTemp = i;
        for (int j = 1; j < tempNum; j++)
        {
            tempAtoms[++i] = tempAtoms[iTemp];
        }
    }

    // get the 2atom bonds
    std::getline(inStream, line);
    std::istringstream iss(line);
    std::string        identifer, numOf2ABonds;
    iss >> identifer >> numOf2ABonds;

    if (identifer.compare("2B") != 0)
    {
        std::cout << "failed to find 2 atoms bond config for " << name << "\n";
        exit(EXIT_FAILURE);
    }

    std::string numOf2ABondsErr =
        "<Invalid number of atoms in molecule \"" + name + "\"\n";
    int numOfTwoAtomBonds = readlib::readINT(numOf2ABonds, numOf2ABondsErr);

    // allocate 2 bonds poitner
    std::vector<twoBonds_t> temp2Bonds(numOfTwoAtomBonds);

    //  get the 2 Atom Bonds
    for (int i = 0; i < numOfTwoAtomBonds && readOk; i++)
    {
        std::cout << numOfTwoAtomBonds << '\n';
        std::getline(inStream, line);
        std::cout << line << "\n--" << i << '\n';
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
                         int                atomNum,
                         int&               inNumOfAtoms) const
{
    std::istringstream iss(inStream);
    std::string        name, word, numOfAtoms;

    iss >> name;
    iss >> word;
    iss >> numOfAtoms;
    double inMass;
    std::cout << "name is " << name << "\n";
    std::cout << "word is " << word << "\n";

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
        inNumOfAtoms = readlib::readINT(numOfAtoms, errText);
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
                           int                bondNum) const
{

    std::istringstream iss(inStream);
    std::string        bondName, inAtom1, inAtom2, inParam1, inParam2;

    std::string errText = "Argument is invalid\n"
                          "The molecule is \"" +
                          molName + "\"\n" + "Bond number is " +
                          std::to_string(bondNum) + "\n";

    iss >> bondName;
    iss >> inAtom1 >> inAtom2;
    iss >> inParam1 >> inParam2;

    // read in atoms
    int atom1 = readlib::readINT(inAtom1, errText);
    int atom2 = readlib::readINT(inAtom2, errText);

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
