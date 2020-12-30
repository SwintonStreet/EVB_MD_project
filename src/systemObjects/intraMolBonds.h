// used to retrieve the 2atom bonds
// and to store the functions themself

#ifndef INTRAMOLBONDS_H
#define INTRAMOLBONDS_H

#include <iostream>
#include <map>
#include <atom.h>
#include <functional>
#include <cmath>
#include "stdlib.h" // for the exit statement


//energyForce_t type1(atom,atom,double,double);


enum intraMolBondsType
{
    VAM_DER_WAALS,
};

struct intraMol_t
{
    int atomA, atomB;
    double param1, param2;
};

class intraMolBonds
{
    constexpr static const char* className {"twoAtomBond"};

    public:

    static std::map<std::string,intraMolBondsType> string2intraMolBonds;

    //constructor
    intraMolBonds() = default;

    static intraMolBondsType get2AtomBond(std::string&);
};


#endif // INTRAMOLBONDS_H
