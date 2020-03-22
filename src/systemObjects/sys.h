
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
    //molecule** molecules;
    std::vector<int> numOfMol;
    std::vector<std::vector<molecule>> molecules;
    double sysEnergy;
    // number of molecules types


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


    const std::vector<int>& getNumOfMol() const {return numOfMol;};
    const std::vector<std::vector<molecule>>& getMols() const {return molecules;};
    int getNumOfMolTypes() const {return numOfMolTypes;}


    void printSysPos(std::ostream&);
};

#endif // SYS_H
