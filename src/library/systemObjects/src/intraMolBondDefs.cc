#include "intraMolBondDefs.h"

#include <string>

using std::string;

intraMolBondDefs::intraMolBondDefs(string&& mol1,
                                   string&& mol2,
                                   string&& atom1,
                                   string&& atom2) :
    molecule_1{mol1},
    molecule_2{mol2}, atom_1{atom1}, atom_2{atom2}
{
}
