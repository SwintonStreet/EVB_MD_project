// molecule class

#ifndef MOLECULE_H
#define MOLECULE_H

#include "iostream"
#include "string"
#include "vector"
#include "twoAtomBonds.h"
#include "atom.h"

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

    molecule(std::string&&             inName,
             std::vector<atom>&&       numAtoms,
             std::vector<twoBonds_t>&& num2Bonds);
    molecule(const molecule& inMol);
    molecule(): mSize{0}, mName{""} {};
    
    // destructor
    //~molecule();

    // clone assignment operator
    //molecule& operator=(const molecule& rhs) {};

    twoBonds_t& get2Bond(int);
    std::vector<twoBonds_t>& getAll2Bond() {return twoBonds;};
    std::string getName() const {return mName;};
    int         getSize() const {return mSize;};

    void setAtom(int         atomNumber,
                 const atom& newAtom);

    [[nodiscard]] atom& getAtom(int atomNumber) {return atoms[atomNumber];};
    [[nodiscard]] std::vector<atom>& getAtoms() {return atoms;};

    void resetForces();

    friend std::ostream& operator<< (std::ostream& oStream,
                                     molecule      mol)
    {
        oStream << "The molecules name is " << mol.mName << "\n";

        for (const atom& at : mol.atoms)
        {
            oStream << at;
        }

        return oStream;
    }

    bool operator() () {return isOk;}
};

#endif // MOLECULE_H
