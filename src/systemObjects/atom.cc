// every bit of information relating to a atom

#include "atom.h"
#include "cmath"

void atom::cp3Array(threeVec_t A, threeVec_t& B)
{
    B.x = A.x; B.y = A.y; B.z = A.z;
}

void atom::setPos(threeVec_t inPos)
{
    cp3Array(inPos, pos);
}

void atom::setVel(threeVec_t inVel)
{
    cp3Array(inVel, vel);
}

void atom::setForc(threeVec_t inForc)
{
    cp3Array(inForc, forc);
}



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

void atom::printAtomPos(std::ostream& inStream)
{
    inStream << "The atoms name is: " << name <<
                 " X:" << pos.x <<
                 " Y:" << pos.y <<
                 " Z:" << pos.z << "\n";
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
