
#include "molReader.h"

molReader::molReader()
{
}

/*
*
* Reads a SYS_MOLECULE file
*
*/

std::vector<molecule> molReader::MolConfReader()
{
    std::ifstream molFile(molReader::defaultFileName);
    std::string   line;
    std::vector<molecule> outMolecule;

    std::cout << "Got here\n";

    if (molFile.is_open())
    {
        while(std::getline(molFile,line))
        {
            if (line[0] == 'M')
            {
                outMolecule.push_back(readSingleMol(molFile));
            }
        }
    }
    return outMolecule;
}

/*
*
* reads a single molecule when the main loop finds the M character
*
*/

molecule molReader::readSingleMol(std::ifstream& inStream)
{
    bool readOk = true;
    std::string name,line;
    std::getline(inStream,name);
    std::getline(inStream,line);
    std::string numOfAtomsErr = "Invalid number of atoms in molecule \"" +
                                name + "\"\n";
    int numOfAtoms = readlib::readINT( line, numOfAtomsErr );
    int tempNum = 1;

    //molecule outMolecule = molecule(name,numOfAtoms);
    atom* tempAtoms = new atom[numOfAtoms];

    //get the atoms
    for (int i=0; i<numOfAtoms && readOk; i++)
    {
        std::getline(inStream,line);
        std::cout << line << std::endl;
        std::cout << "--" << i << std::endl;
        readOk = readAtom(line,
                          tempAtoms[i],
                          name,
                          i,
                          tempNum);
        int iTemp = i;
        for (int j = 1; j<tempNum; j++)
        {
            tempAtoms[++i] = tempAtoms[iTemp];
        }
    }

    // get the 2atom bonds
    std::getline(inStream,line);
    std::istringstream iss(line);
    std::string identifer, numOf2ABonds;
    iss >> identifer;
    iss >> numOf2ABonds;

    if ( identifer.compare("2B") != 0)
    {
        std::cout << "failed to find 2 atoms bond config for " << name << "\n";
        exit (EXIT_FAILURE);
    }
    
    std::string numOf2ABondsErr = "Invalid number of atoms in molecule \"" + name + "\"\n";
    int numOfTwoAtomBonds = readlib::readINT( numOf2ABonds, numOf2ABondsErr );

    // allocate 2 bonds poitner
    twoBonds_t* temp2Bonds = new twoBonds_t[numOfTwoAtomBonds];

    //  get the 2 Atom Bonds
    for (int i=0; i<numOfTwoAtomBonds && readOk; i++)
    {
        std::cout << numOfTwoAtomBonds << "\n";
        std::getline(inStream,line);
        std::cout << line << std::endl;
        std::cout << "--" << i << std::endl;
        readOk = read2ABond(line,
                            temp2Bonds[i],
                            name,
                            i);
    }

    // creating the molecule object
    molecule outMolecule = molecule(name,
                                    numOfAtoms,
                                    numOfTwoAtomBonds);

    // copy the atoms in
    for (int i=0; i< numOfAtoms;i++)
    { outMolecule.setAtom(i,tempAtoms[i]); }

    // copy the 2 atom bonds in
    for (int i=0; i< numOfTwoAtomBonds; i++)
    { outMolecule.get2Bond(i) = temp2Bonds[i]; }

    // delete used pointers;
    delete[] tempAtoms;
    delete[] temp2Bonds;

    return outMolecule;
}

/*
*
* reads a single atom
*
*/

bool molReader::readAtom(std::string inStream,
                         atom&       inAtom,
                         std::string molName,
                         int         atomNum,
                         int&        inNumOfAtoms)
{
    std::istringstream iss(inStream);
    std::string        name       = "",
                       word       = "",
                       numOfAtoms = "";

    iss >> name;
    iss >> word;
    iss >> numOfAtoms;
    double inMass; 
    std::cout << "name is " << name << "\n";
    std::cout << "word is " << word << "\n";

    std::string errText =   "Argument is invalid\n"
                            "The molecule is \"" +  molName + "\"\n" +
                            "Atom number is " + std::to_string(atomNum) + "\n";
    inMass = readlib::readDOU(word,errText);

    inAtom = atom(name,inMass);

    if (numOfAtoms.empty())
    {
        inNumOfAtoms = 1;
    }
    else
    {
        inNumOfAtoms = readlib::readINT(numOfAtoms,errText);
    }

    return true;
}

/*
*
* reads the informtion to define a 2 atom bond
*
*/

bool molReader::read2ABond(std::string&   inStream,
                           twoBonds_t&    inBond,
                           std::string    molName,
                           int            bondNum)
{

    std::istringstream iss(inStream);
    std::string bondName, inAtom1, inAtom2, inParam1, inParam2;

    std::string errText =   "Argument is invalid\n"
                            "The molecule is \"" +  molName + "\"\n" +
                            "Bond number is " + std::to_string(bondNum) + "\n";

    iss >> bondName;
    iss >> inAtom1  >> inAtom2;
    iss >> inParam1 >> inParam2;

    //read in atoms
    int atom1  = readlib::readINT(inAtom1,errText);
    int atom2  = readlib::readINT(inAtom2,errText);

    // read in params
    double param1 = readlib::readDOU(inParam1,errText);
    double param2 = readlib::readDOU(inParam2,errText);

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
