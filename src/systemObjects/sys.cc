#include "sys.h"

sys::sys(const int                    inNumOfMolTypes,
         std::vector<int>             inNumOfMol,
         const std::vector<molecule>& inMol)
    : numOfMolTypes(inNumOfMolTypes),
      numOfMol(std::vector<int>(inNumOfMolTypes)),
      molecules(std::vector<std::vector<molecule>>(inNumOfMolTypes)),
      sysEnergy(0)
{
    // this assigns the number of molecules in each molecule type
    // then the set up each molecule as a copy of the

    std::cout << "No. of mol types: " << numOfMolTypes << '\n';
    for (int i = 0; i < numOfMolTypes; ++i)
    {
        std::cout << "setting mol: " << i << '\n';
        molecules[i] = std::vector<molecule>(inNumOfMol[i]);
        numOfMol[i]  = inNumOfMol[i];
        for (int j = 0; j < inNumOfMol[i]; ++j)
        {
            std::cout << "==1== " << j << '\n';
            molecules[i][j] = inMol[i];
        }
    }
}

// copy constuctor
sys::sys(const sys& inSys)
    : numOfMolTypes(inSys.getNumOfMolTypes()), sysEnergy(0)
{
    numOfMol  = inSys.getNumOfMol();
    molecules = inSys.getMols();
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

void sys::printSysPos(std::ostream& inStream)
{
    for (const auto& molVec : molecules)
    {
        for (const auto& mol : molVec)
        {
            inStream << mol;
        }
    }
}
