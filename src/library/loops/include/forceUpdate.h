// sys update class header

#ifndef FORCEUPDATE_H
#define FORCEUPDATE_H

#include "atom.h"
#include "molecule.h"
#include "sys.h"
#include "twoBondLoop.h"
#include "vector"

class forceUpdate
{
  public:
    static void forcUpdate(sys&);

    static void resetForce(sys&);

    static void interMolForc(sys&, molecule&, const int&, const int&);
};

#endif // FORCEUPDATE_H
