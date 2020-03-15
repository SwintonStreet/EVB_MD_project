
// evb_system class

#include "iostream"
#include "sys.h"
#include <string>

class evb_system
{
    sys       systems;
    // number of systems
    const int size;

    std::string name;

    public:

    evb_system(const int   inSize,
               sys&        inSys,
               std::string inName): systems{inSys},
                                    size{inSize},
                                    name{inName}
    {}

    int getSize() const noexcept {return size;}
};
