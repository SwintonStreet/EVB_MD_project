#include "molecule.h"

molecule::molecule(std::string&             inName,
                   std::vector<atom>&       inAtoms,
                   std::vector<twoBonds_t>& in2Bonds) :
    mSize{inAtoms.size()},
    mName{inName}, atoms(inAtoms), twoBonds(in2Bonds), isOk{true}
{
}

// copy constructor
molecule::molecule(const molecule& inMol) :
    mSize{inMol.mSize}, mName{inMol.mName}, atoms(inMol.atoms),
    twoBonds(inMol.twoBonds), isOk{true}
{
}

void molecule::setAtom(size_t atomNumber, const atom& inAtom)
{
    atoms[atomNumber] = inAtom;
}

twoBonds_t& molecule::get2Bond(size_t bondNumber)
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
