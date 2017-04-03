
// evb_system class

#include "iostream"
#include "sys.h"

class evb_system
{
    static sys*      systems;
    // number of systems
    static const int size;


    public:

    evb_system(int, sys*, char*);
};
