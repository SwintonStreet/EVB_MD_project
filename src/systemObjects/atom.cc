// every bit of information relating to a atom

#include "atom.h"
#include "iostream"
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


atom::atom( threeVec_t    inPos ,
            threeVec_t    inVel ,
            threeVec_t    inForc,
            std::string   inName)
{
    setPos( inPos );
    setVel( inVel );
    setForc(inForc);

    name = inName;
}


atom::atom(std::string inName,
           double      inMass)
{
    name = inName;
    mass = inMass;
}

void atom::printAtom(std::ostream& inStream)
{
    inStream
    << "===============================" << std::endl
    << "The name of the atom is " << name
    << std::endl << "The position is " <<
    pos.x << ","  << pos.y << ","  << pos.z
    << std::endl  << "The velocity is " <<
    vel.x << ","  << vel.y<< ","   << vel.z
    << std::endl << "The force is " <<
    forc.x << "," << forc.y << "," << forc.z << std::endl
    << "===============================" << std::endl;

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
    double dis = 0;

    dis = std::sqrt(
            std::pow((pos.x - inAtom.getPos().x),2) +
            std::pow((pos.y - inAtom.getPos().y),2) +
            std::pow((pos.z - inAtom.getPos().z),2));

    return dis;
}

threeVec_t atom::abVec(atom& inAtom)
{
    return {pos.x - inAtom.getPos().x,
            pos.y - inAtom.getPos().y,
            pos.z - inAtom.getPos().z};
}
