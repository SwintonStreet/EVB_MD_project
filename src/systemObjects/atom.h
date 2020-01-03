// Atom class header

#ifndef ATOM_H
#define ATOM_H

#include "string"
#include "iostream"


struct energyForce_t
{
    double engFor[4];
};

struct threeVec_t
{
    double x, y, z;

    friend threeVec_t operator*(const double&    factor,
                                const threeVec_t b)
    {
        return {factor * b.x,
                factor * b.y,
                factor * b.z};
    }

    threeVec_t operator+(const threeVec_t b)
    {
        return {x+b.x,y+b.y,z+b.z};
    }

    threeVec_t operator-(const threeVec_t b)
    {
        return {x-b.x,y-b.y,z-b.z};
    }

    friend std::ostream& operator<< (std::ostream&     inStream,
                                     const threeVec_t& vec)
    {
        inStream << vec.x << "," << vec.y << "," << vec.z;
        return inStream;
    }
};

class atom 
{
    
    threeVec_t  pos, vel, forc;
    double      mass;
    std::string name;

    public:

    // Copy a 3 lenth array
    void cp3Array(threeVec_t, threeVec_t&);

    // Empty constructor
    atom();
    
    // copy constructor
    atom(const atom&);

    // non-empty constructor
    // This includes
    // Position vector
    // Velocity vector
    // force vector
    // Name
    atom( threeVec_t, threeVec_t, threeVec_t, std::string );

    atom(std::string,double);


    // sets the position,velocity,force
    void setPos (threeVec_t);
    void setVel (threeVec_t);
    void setForc(threeVec_t);

    // print atom information
    void printAtom(std::ostream&);
    void printAtomPos(std::ostream&);
    
    // gets the position,velocity,force
    threeVec_t getPos () const noexcept {return pos;};
    threeVec_t getVel () const noexcept {return vel;};
    threeVec_t getForc() const noexcept {return forc;};

    // reset force
    void resetForce() { forc = {0,0,0}; };

    // get name
    std::string getName() const noexcept {return name;};
    double      getMass() const noexcept {return mass;};

    // calculate distance between atom and another atom
    double distance(atom&);
    threeVec_t abVec(atom&);

    friend std::ostream& operator<< (std::ostream& oStream,
                                     atom          a)
    {
        oStream << "The atoms name is: " << a.name <<
                   " X:" << a.pos.x <<
                   " Y:" << a.pos.y <<
                   " Z:" << a.pos.z << "\n";
        return oStream;
    }
};

#endif // ATOM_H
