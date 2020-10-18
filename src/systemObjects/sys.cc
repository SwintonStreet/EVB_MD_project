#include "sys.h"

sys::sys(const int                    inNumOfMolTypes,
         std::vector<int>             inNumOfMol,
         const std::vector<molecule>& inMol) :
    numOfMolTypes(inNumOfMolTypes),
    numOfMol(std::vector<int>(inNumOfMolTypes)),
    molecules(std::vector<std::vector<molecule>>(inNumOfMolTypes)), sysEnergy(0)
{
    // this assigns the number of molecules in each molecule type
    // then the set up each molecule as a copy of the

    for (int i = 0; i < numOfMolTypes; ++i)
    {
        molecules[i] = std::vector<molecule>(inNumOfMol[i]);
        numOfMol[i]  = inNumOfMol[i];
        for (int j = 0; j < inNumOfMol[i]; ++j)
        {
            molecules[i][j] = inMol[i];
        }
    }
}

// copy constuctor
sys::sys(const sys& inSys) :
    numOfMolTypes(inSys.getNumOfMolTypes()), numOfMol{inSys.getNumOfMol()},
    molecules{inSys.getMols()}, sysEnergy(0)
{
}

// move constuctor
sys::sys(sys&& inSys) noexcept :
    numOfMolTypes(inSys.getNumOfMolTypes()), numOfMol{inSys.getNumOfMol()},
    molecules{inSys.getMols()}, sysEnergy{0}
{
}

void sys::resetAllForces()
{
    for (auto& molvec : molecules)
    {
        for (auto& mol : molvec)
        {
            mol.resetForces();
        }
    }
}
