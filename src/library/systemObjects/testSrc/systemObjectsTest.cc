#include "atom.h"
#include "molecule.h"
#include "twoAtomBonds.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(moleculeTests, name)
{
    std::vector<atom>       atoms;
    std::vector<twoBonds_t> twoAtomBonds;
    std::string             name{"myMolecule"};

    molecule m(name, atoms, twoAtomBonds);

    ASSERT_EQ("myMolecule", m.getName());
}

TEST(atomTests, copy)
{
    atom a{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, "TestAtom"};

    atom b{a};
    ASSERT_EQ(a.getName(), b.getName());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}