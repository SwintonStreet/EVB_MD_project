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

    // c'tors
    molecule(std::string&             inName,
             std::vector<atom>&       inAtoms,
             std::vector<twoBonds_t>& in2Bonds);
    molecule(): mSize{0}, mName{""} {};

    // copy c'tor
    molecule(const molecule& inMol);

    // defaulted move c'tor & copy/move assignment
    molecule(molecule&&) = default;
    molecule& operator=(const molecule&) = default;
    molecule& operator=(molecule&&) = default;

    // destructor
    ~molecule() = default;

    // clone assignment operator
    //molecule& operator=(const molecule& rhs) {};

    twoBonds_t& get2Bond(int);
    const std::vector<twoBonds_t>& getAll2Bond() const {return twoBonds;};
    std::string getName() const {return mName;};
    int         getSize() const {return mSize;};

    void setAtom(int         atomNumber,
                 const atom& inAtom);

    [[nodiscard]] atom& getAtom(int atomNumber) {return atoms[atomNumber];};
    [[nodiscard]] std::vector<atom>& getAtoms() {return atoms;};

    void resetForces();

    friend std::ostream& operator<< (std::ostream& oStream,
                                     molecule      mol)
    {
        oStream << "The molecules name is " << mol.mName << '\n';

        for (const atom& at : mol.atoms)
        {
            oStream << at;
        }

        return oStream;
    }

    bool operator() () {return isOk;}
};

#endif // MOLECULE_H
