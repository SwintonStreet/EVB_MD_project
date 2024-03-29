// every bit of information relating to a atom
#include "atom.h"

#include <cmath>

atom::atom(const atom& inAtom) : name{inAtom.getName()}
{
    mass = inAtom.getMass();

    setPos(inAtom.getPos());
    setVel(inAtom.getVel());
    setForc(inAtom.getForc());
}

atom& atom::operator=(const atom& inAtom)
{
    name = inAtom.getName();
    mass = inAtom.getMass();

    setPos(inAtom.getPos());
    setVel(inAtom.getVel());
    setForc(inAtom.getForc());

    return *this;
}

atom::atom(const threeVec_t& inPos,
           const threeVec_t& inVel,
           const threeVec_t& inForc,
           std::string&&     inName) :
    name{inName}
{
    setPos(inPos);
    setVel(inVel);
    setForc(inForc);
}

atom::atom(const std::string& inName, const double inMass) : name{inName}
{
    mass = inMass;
}

void atom::printAtom(std::ostream& inStream) const noexcept
{
    inStream << "===============================\n"
             << "The name of the atom is " << name << "The position is " << pos
             << '\n'
             << "The velocity is " << vel << '\n'
             << "The force is " << forc << '\n'
             << "===============================\n";
}

double atom::distance(const atom& bAtom) const
{
    const threeVec_t& ab = abVec(bAtom);

    return std::sqrt(std::pow(ab.x, 2) + std::pow(ab.y, 2) + std::pow(ab.z, 2));
}

threeVec_t atom::abVec(const atom& bAtom) const noexcept
{
    const threeVec_t& bPos = bAtom.getPos();

    return {pos.x - bPos.x, pos.y - bPos.y, pos.z - bPos.z};
}
