
#include "twoAtomBonds.h"
#include "logger.h"

twoAtomBonds::twoAtomBonds() {}

// definition of mapping from string to two atom bond type
std::map<std::string, twoAtomBondName> twoAtomBonds::string2AtomBond = {
    {"SPRING", SIMPLE_SPRING},
    {"TMP", TYPE_2}};

double twoAtomBonds::calc2AtomEngFor(const twoBonds_t& inBond,
                                     atom&             atom1,
                                     atom&             atom2)
{
    double energy = 0;
    switch (inBond.bondName)
    {
    case SIMPLE_SPRING:
        energy = simpleSpring(atom1, atom2, inBond);
        break;
    case TYPE_2:
        break;
    default:
        LOGTOSCREEN("Error found in twoAtomBonds class\n"
                    "Unknown bond!!\n");
        exit(EXIT_FAILURE);
    }
    return energy;
}

double
twoAtomBonds::simpleSpring(atom& atomA, atom& atomB, const twoBonds_t& inBond)
{
    // do some stuff.
    double eng = 0.5 * inBond.param1 *
                 std::pow(inBond.param2 - atomA.distance(atomB), 2);
    threeVec_t abVec = -inBond.param1 * atomA.abVec(atomB);
    updateForce(abVec, atomA, atomB);
    return eng;
}

twoAtomBondName twoAtomBonds::get2AtomBond(std::string& inString)
{
    twoAtomBondName out2AtomBondName;
    auto            it = string2AtomBond.find(inString);
    if (it != string2AtomBond.end())
    {
        out2AtomBondName = it->second;
    }
    else
    {
        LOGTOSCREEN("Error in twoAtomBonds\n"
                    "Failed to find 2 atom bond named " + inString +
                    "in map\n");
        exit(EXIT_FAILURE);
    }
    return out2AtomBondName;
}

void twoAtomBonds::updateForce(const threeVec_t& inVec,
                               atom&             atomA,
                               atom&             atomB)
{
    atomA.setForc(atomA.getForc() + inVec);
    atomB.setForc(atomB.getForc() - inVec);
}
