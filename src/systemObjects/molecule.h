// molecule class

#ifndef MOLECULE_H
#define MOLECULE_H

#include "iostream"
#include "string"
#include "vector"
#include "twoAtomBonds.h"

class atom;

class molecule
{
    // number of atoms
    int                     mSize;
    std::string             mName;
    std::vector<atom>       atoms;
    std::vector<twoBonds_t> twoBonds;
    bool                    isOk;

    public:


    molecule(std::string, int, int);
    molecule(const molecule&);
    molecule();
    
    // destructor
    //~molecule();

    // clone assignment operator
    //molecule& operator=(const molecule& rhs) {};

    twoBonds_t& get2Bond(int);
    std::vector<twoBonds_t>& getAll2Bond() {return twoBonds;};
    std::string getName() const {return mName;};
    int         getSize() const {return mSize;};

    void        setAtom(int, const atom&);
    atom&       getAtom(int);
    std::vector<atom>& getAtoms() {return atoms;};

    void printMolPos(std::ostream&);
    void resetForces();



};

#endif // MOLECULE_H
