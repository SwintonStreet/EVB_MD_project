// system class
#ifndef SYS_H
#define SYS_H

#include <iostream>
#include <vector>

#include "molecule.h"

// class molecule;

class sys
{
    const size_t                       numOfMolTypes;
    std::vector<size_t>                numOfMol;
    std::vector<std::vector<molecule>> molecules;
    double                             sysEnergy;

  public:
    sys();
    sys(const sys&);
    sys(sys&&) noexcept;

    sys operator=(const sys&) = delete;
    sys operator=(sys&&)      = delete;

    sys(const size_t, std::vector<size_t>, const std::vector<molecule>&);

    std::vector<size_t>&                getNumOfMol() { return numOfMol; };
    std::vector<std::vector<molecule>>& getMols() { return molecules; };
    void                                resetEnergy() { sysEnergy = 0; }
    void addEnergy(double inEn) { sysEnergy += inEn; }
    void resetAllForces();

    size_t getNumOfMolTypes() const { return numOfMolTypes; }

    const std::vector<size_t>& getNumOfMol() const { return numOfMol; };
    const std::vector<std::vector<molecule>>& getMols() const
    {
        return molecules;
    };

    friend std::ostream& operator<<(std::ostream& os, const sys& s)
    {
        for (const auto& molVec : s.molecules)
        {
            for (const auto& mol : molVec)
            {
                os << mol;
            }
        }
        return os;
    }
};

#endif // SYS_H
