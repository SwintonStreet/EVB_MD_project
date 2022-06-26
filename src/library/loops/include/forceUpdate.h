// sys update class header

#ifndef FORCEUPDATE_H
#define FORCEUPDATE_H

#include "vector"
#include "sys.h"
#include "molecule.h"
#include "atom.h"
#include "twoBondLoop.h"


class forceUpdate
{
    public:

    static void forcUpdate(sys&);

    static void resetForce(sys&);

    static void interMolForc(sys&,
                             molecule&,
                             const int&,
                             const int&);

};

#endif // FORCEUPDATE_H
