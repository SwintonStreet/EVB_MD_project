
#include "forceUpdate.h"

void forceUpdate::forcUpdate(sys& inSys)
{
    double totalEnergy = 0;
    int i = 0,
        j = 0;

    for (auto vecMol : inSys.getMols())
    {
        for(auto mol : vecMol)
        {
            // calculate bonds
            totalEnergy += twoBondLoop::
                               calcEngForTwoBond(
                                  mol.getAll2Bond(),
                                  mol.getAtoms());

            // calculate intermolcular forces
            interMolForc(inSys,mol,j++,i);
        }
        j = 0;
        ++i;
    }
}

void forceUpdate::resetForce(sys& inSys)
{
    for (auto molVec : inSys.getMols())
    {
        for (auto mol : molVec)
        {
            for (auto atom : mol.getAtoms())
            {
                atom.setForc({0,0,0});
            }
        }
    }
}

void forceUpdate::interMolForc(sys&       inSys,
                               molecule&  inMol,
                               const int& molType,
                               const int& molNum)
{
    auto molVec = inSys.getMols();

    for (int i = molType; i < static_cast<int>(molVec.size()); ++i)
    {
        for (int j = molNum; j < static_cast<int>(molVec[i].size()); ++j)
        {
            // do stuff
        }
    }
}
