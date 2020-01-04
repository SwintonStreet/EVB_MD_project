#include "molecule.h"
#include "atom.h"

molecule::molecule(std::string inName,
                   int         inASize,
                   int         in2BSize)
                  :mSize(inASize),
                   mName(inName.c_str()),
                   atoms(std::vector<atom>(inASize)),
                   twoBonds(std::vector<twoBonds_t>(in2BSize))
{
}

molecule::molecule()
                 :mSize(0),
                  mName("")
{
}

// copy constructor
molecule::molecule(const molecule& inMol)
                 :mSize(inMol.mSize),
                  mName(inMol.mName)
{
    atoms    = std::vector<atom>(inMol.atoms);
    twoBonds = std::vector<twoBonds_t>(inMol.twoBonds);
}

atom& molecule::getAtom(int atomNumber)
{
    return molecule::atoms[atomNumber];
}

void molecule::setAtom(int          atomNumber,
                       const atom&  inAtom)
{
    atoms[atomNumber] = inAtom;
}


twoBonds_t& molecule::get2Bond(int bondNumber)
{
    return twoBonds[bondNumber];
}

void molecule::printMolPos(std::ostream& inStream)
{
    inStream << "The molecules name is " << mName << "\n";

    for (const atom& at : atoms)
    {
        inStream << at;
    }
}

void molecule::resetForces()
{
    for (auto atom : atoms)
    {
        atom.resetForce();
    }
}
