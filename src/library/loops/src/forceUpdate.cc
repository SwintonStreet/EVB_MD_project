#include "forceUpdate.h"

void forceUpdate::forcUpdate(sys& inSys)
{
    [[maybe_unused]] double totalEnergy = 0;
    size_t                  i           = 0;
    size_t                  j           = 0;

    for (auto& vecMol : inSys.getMols())
    {
        for (auto& mol : vecMol)
        {
            // calculate bonds
            totalEnergy += twoBondLoop::calcEngForTwoBond(mol.getAll2Bond(),
                                                          mol.getAtoms());

            // calculate intermolcular forces
            interMolForc(inSys, mol, j++, i);
        }
        j = 0;
        ++i;
    }
}

void forceUpdate::resetForce(sys& inSys)
{
    for (auto& molVec : inSys.getMols())
    {
        for (auto& mol : molVec)
        {
            for (auto& atom : mol.getAtoms())
            {
                atom.setForc({0, 0, 0});
            }
        }
    }
}

void forceUpdate::interMolForc(sys&          inSys,
                               molecule&     inMol,
                               const size_t& molType,
                               const size_t& molNum)
{
    auto molVec = inSys.getMols();

    for (size_t i = molType; i < molVec.size(); ++i)
    {
        for (size_t j = molNum; j < molVec[i].size(); ++j)
        {
            // do stuff
            (void)inMol;
        }
    }
}
