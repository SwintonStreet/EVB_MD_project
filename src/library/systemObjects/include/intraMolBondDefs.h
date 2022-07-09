// used to retrieve the 2atom bonds
// and to store the functions themself

#ifndef INTRAMOLBONDDEFS_H
#define INTRAMOLBONDDEFS_H

#include <cmath>
#include <cstdlib> // for the exit statement
#include <functional>
#include <iostream>
#include <map>
#include <string>

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
    intraMolBondDefs(std::string&& mol1,
                     std::string&& mol2,
                     std::string&& atom1,
                     std::string&& atom2);

  private:
    std::string molecule_1;
    std::string molecule_2;
    std::string atom_1;
    std::string atom_2;
};

#endif // INTRAMOLBONDDEFS_H
