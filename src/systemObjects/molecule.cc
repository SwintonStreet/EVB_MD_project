#include "molecule.h"

molecule::molecule(std::string& inName,
                   int          inASize,
                   int          in2BSize)
                  :mSize{inASize},
                   mName{inName},
                   atoms(inASize),
                   twoBonds(in2BSize)
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
