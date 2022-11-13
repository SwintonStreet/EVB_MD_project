#include "twoBondLoop.h"

#include <vector>

using std::vector;

double twoBondLoop::calcEngForTwoBond(const vector<twoBonds_t>& bondVec,
                                      vector<atom>&             atomvec)
{
    for (const auto& bond : bondVec)
    {
        twoAtomBonds::calc2AtomEngFor(
            bond, atomvec[bond.atomA], atomvec[bond.atomB]);
    }

    return 0;
}

void twoBondLoop::calcEngForSysTwoBond(sys& inSys)
{
    vector<vector<molecule>>& vecVecMol   = inSys.getMols();
    double                    totalEnergy = 0;

    for (auto& vecMol : vecVecMol)
    {
        for (auto& mol : vecMol)
        {
            totalEnergy += calcEngForTwoBond(mol.getAll2Bond(), mol.getAtoms());
        }
    }

    inSys.addEnergy(totalEnergy);
}
