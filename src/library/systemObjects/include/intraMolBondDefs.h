// used to retrieve the 2atom bonds
// and to store the functions themself

#ifndef INTRAMOLBONDDEFS_H
#define INTRAMOLBONDDEFS_H

#include "stdlib.h" // for the exit statement
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>

using std::string;

enum intraMolBondsType
{
    VAM_DER_WAALS,
};

class intraMolBondDefs
{
    constexpr static const char* className{"intraMolBondDefs"};

  public:
    static std::map<std::string, intraMolBondsType> string2intraMolBonds;

    // constructor
    intraMolBondDefs(string&& mol1,
                     string&& mol2,
                     string&& atom1,
                     string&& atom2);

  private:
    string molecule_1;
    string molecule_2;
    string atom_1;
    string atom_2;
};

#endif // INTRAMOLBONDDEFS_H
