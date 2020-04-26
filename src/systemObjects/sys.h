
// system class

#ifndef SYS_H
#define SYS_H

#include "iostream"
#include "vector"
#include "molecule.h"

//class molecule;

class sys
{
    const int numOfMolTypes;
    std::vector<int> numOfMol;
    std::vector<std::vector<molecule>> molecules;
    double sysEnergy;

    public:

    sys();
    sys(const sys&);

    sys(const int,
        std::vector<int>,
        const std::vector<molecule>&);

    std::vector<int>& getNumOfMol() {return numOfMol;};
    std::vector<std::vector<molecule>>& getMols() {return molecules;};
    void resetEnergy() {sysEnergy = 0;}
    void addEnergy(double inEn)   {sysEnergy += inEn;}
    void resetAllForces();

    int getNumOfMolTypes() const {return numOfMolTypes;}

    const std::vector<int>& getNumOfMol() const {return numOfMol;};
    const std::vector<std::vector<molecule>>& getMols() const {return molecules;};

    void printSysPos(std::ostream&);
};

#endif // SYS_H
