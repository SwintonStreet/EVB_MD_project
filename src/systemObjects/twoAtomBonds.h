// used to retrieve the 2atom bonds
// and to store the functions themself

#ifndef TWOATOMBONDS_H
#define TWOATOMBONDS_H

#include <iostream>
#include <map>
#include <atom.h>
#include <functional>
#include <cmath>
#include "stdlib.h" // for the exit statement


//energyForce_t type1(atom,atom,double,double);


enum twoAtomBondName
{
    SIMPLE_SPRING,
    TYPE_2
};

struct twoBonds_t
{
    int atomA, atomB;
    double param1, param2;
    twoAtomBondName bondName;
};

class twoAtomBonds
{

    public:

    static std::map<std::string,twoAtomBondName> string2AtomBond;

    //constructor
    twoAtomBonds();
    static double calc2AtomEngFor(const twoBonds_t&,
                                  atom&,
                                  atom&);

    static double simpleSpring(atom&,
                               atom&,
                               const twoBonds_t&);

    static void updateForce(const threeVec_t&,
                            atom&,
                            atom&);

    static twoAtomBondName get2AtomBond(std::string&);


};


#endif // TWOATOMBONDS_H
