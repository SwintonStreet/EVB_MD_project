// sys update class header
#ifndef FORCEUPDATE_H
#define FORCEUPDATE_H

#include <vector>

#include "atom.h"
#include "molecule.h"
#include "sys.h"
#include "twoBondLoop.h"

class forceUpdate
{
  public:
    static void forcUpdate(sys&);

    static void resetForce(sys&);

    static void interMolForc(sys&, molecule&, const int&, const int&);
};

#endif // FORCEUPDATE_H
