// every bit of information relating to a atom

#include "atom.h"
#include "cmath"

atom::atom ()
{
}

atom::atom(const atom& inAtom)
{
    name = inAtom.getName();
    mass = inAtom.getMass();

    setPos(inAtom.getPos());
    setVel(inAtom.getVel());
    setForc(inAtom.getForc());
}


atom::atom( threeVec_t  inPos,
            threeVec_t  inVel,
            threeVec_t  inForc,
            std::string inName) : name {inName}
{
    setPos( inPos );
    setVel( inVel );
    setForc(inForc);
}


atom::atom(std::string inName,
           double      inMass)
{
    name = inName;
    mass = inMass;
}

void atom::printAtom(std::ostream& inStream)
{
    inStream <<
    "===============================\n" <<
    "The name of the atom is " << name <<
    "The position is " << pos  << '\n' <<
    "The velocity is " << vel  << '\n' <<
    "The force is "    << forc << '\n' <<
    "===============================\n";

}

double atom::distance (atom& inAtom)
{
    return std::sqrt(
            std::pow((pos.x - inAtom.getPos().x),2) +
            std::pow((pos.y - inAtom.getPos().y),2) +
            std::pow((pos.z - inAtom.getPos().z),2));
}

threeVec_t atom::abVec(atom& inAtom)
{
    return {pos.x - inAtom.getPos().x,
            pos.y - inAtom.getPos().y,
            pos.z - inAtom.getPos().z};
}
