#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "atom.h"
#include "molecule.h"
#include "twoAtomBonds.h"

using std::string;
using std::vector;

namespace
{

TEST(moleculeTests, name)
{
    vector<atom>       atoms;
    vector<twoBonds_t> twoAtomBonds;
    string             name{"myMolecule"};

    const molecule m(name, atoms, twoAtomBonds);

    ASSERT_EQ("myMolecule", m.getName());
}

TEST(atomTests, copy)
{
    const atom a{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, "TestAtom"};

    const atom b{a};
    ASSERT_EQ(a.getName(), b.getName());
}

} // namespace
