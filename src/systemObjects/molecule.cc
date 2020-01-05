#include "molecule.h"

molecule::molecule(std::string&&             inName,
                   std::vector<atom>&&       inAtoms,
                   std::vector<twoBonds_t>&& in2Bonds)
                  :mSize{static_cast<int>(inAtoms.size())},
                   mName{inName},
                   atoms(inAtoms),
                   twoBonds(in2Bonds)
{
}

// copy constructor
molecule::molecule(const molecule& inMol)
                 :mSize{inMol.mSize},
                  mName{inMol.mName},
                  atoms(inMol.atoms),
                  twoBonds(inMol.twoBonds)
{
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

void molecule::resetForces()
{
    for (atom& at : atoms)
    {
        at.resetForce();
    }
}
