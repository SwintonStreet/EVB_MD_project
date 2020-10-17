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

    // c'tor/d'tor
    threeVec_t()  = default;
    ~threeVec_t() = default;

    friend threeVec_t operator*(const double&     factor,
                                const threeVec_t& b)
    {
        return {factor * b.x,
                factor * b.y,
                factor * b.z};
    }

    threeVec_t operator+(const threeVec_t& b) const
    {
        return {x+b.x,
                y+b.y,
                z+b.z};
    }

    threeVec_t operator-(const threeVec_t& b) const
    {
        return {x-b.x,
                y-b.y,
                z-b.z};
    }

    friend std::ostream& operator<< (std::ostream&     inStream,
                                     const threeVec_t& vec)
    {
        inStream << vec.x << "," << vec.y << "," << vec.z;
        return inStream;
    }

    void reset() noexcept
    {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }

    void set(const threeVec_t& inVec) noexcept
    {
        x = inVec.x;
        y = inVec.y;
        z = inVec.z;
    }
};

class atom
{

    threeVec_t  pos  = { 0.0, 0.0, 0.0 };
    threeVec_t  vel  = { 0.0, 0.0, 0.0 };
    threeVec_t  forc = { 0.0, 0.0, 0.0 };
    double      mass = 0;
    std::string name{""};

    public:

    // Default c'tor/d'tor
    atom() = default;
    ~atom() = default;

    // copy constructor
    atom(const atom&);

    // copy assignment
    atom& operator=(const atom&);

    // defaulted move & copy/move assignment
    atom(atom&&) = default;
    atom& operator=(atom&&) = default;

    // non-empty constructor
    // This includes
    // Position vector
    // Velocity vector
    // force vector
    // Name
    atom( const threeVec_t&,
          const threeVec_t&,
          const threeVec_t&,
          std::string&& );

    atom(const std::string&,const double);

    // sets the position,velocity,force
    void setPos (const threeVec_t& inPos)  {pos.set(inPos);};
    void setVel (const threeVec_t& inVel)  {vel.set(inVel);};
    void setForc(const threeVec_t& inForc) {forc.set(inForc);};

    // print atom information
    void printAtom(std::ostream&) const noexcept;

    // gets the position,velocity,force
    threeVec_t getPos () const noexcept {return pos;};
    threeVec_t getVel () const noexcept {return vel;};
    threeVec_t getForc() const noexcept {return forc;};

    // reset force
    void resetForce() noexcept { forc.reset(); };

    // get name
    std::string getName() const noexcept {return name;};
    double      getMass() const noexcept {return mass;};

    // calculate distance between atom and another atom
    double distance  (const atom&) const;
    threeVec_t abVec (const atom&) const noexcept;

    friend std::ostream& operator<< (std::ostream& oStream,
                                     atom          a)
    {
        oStream << "The atom's name is: " << a.name <<
                   " X:" << a.pos.x <<
                   " Y:" << a.pos.y <<
                   " Z:" << a.pos.z << "\n";
        return oStream;
    }
};

#endif // ATOM_H
