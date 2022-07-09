// molecule class

#ifndef MOLECULE_H
#define MOLECULE_H

#include "atom.h"
#include "iostream"
#include "string"
#include "twoAtomBonds.h"
#include "vector"

class atom;

class molecule
{
    // number of atoms
    size_t                  mSize;
    std::string             mName;
    std::vector<atom>       atoms;
    std::vector<twoBonds_t> twoBonds;
    bool                    isOk;

  public:
    // c'tors
    molecule(std::string&             inName,
             std::vector<atom>&       inAtoms,
             std::vector<twoBonds_t>& in2Bonds);
    molecule() : mSize{0}, mName{""}, atoms{}, twoBonds{}, isOk{true} {};

    // copy c'tor
    molecule(const molecule& inMol);

    // defaulted move c'tor & copy/move assignment
    molecule(molecule&&) = default;
    molecule& operator=(const molecule&) = default;
    molecule& operator=(molecule&&) = default;

    // destructor
    ~molecule() = default;

    // clone assignment operator
    // molecule& operator=(const molecule& rhs) {};

    twoBonds_t&                    get2Bond(int);
    const std::vector<twoBonds_t>& getAll2Bond() const { return twoBonds; };
    [[nodiscard]] std::string      getName() const { return mName; };
    [[nodiscard]] size_t           getSize() const { return mSize; };

    void setAtom(int atomNumber, const atom& inAtom);

    [[nodiscard]] atom& getAtom(int atomNumber) { return atoms[atomNumber]; };
    [[nodiscard]] std::vector<atom>& getAtoms() { return atoms; };

    void resetForces();

    friend std::ostream& operator<<(std::ostream& oStream, molecule mol)
    {
        oStream << "The molecules name is " << mol.mName << '\n';

        for (const atom& at : mol.atoms)
        {
            oStream << at;
        }

        return oStream;
    }

    bool operator()() const noexcept { return isOk; }
};

#endif // MOLECULE_H
