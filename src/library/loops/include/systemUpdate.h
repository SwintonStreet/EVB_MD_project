// sys update class header

#ifndef SYSTEMUPDATE_H
#define SYSTEMUPDATE_H

#include "atom.h"
#include "forceUpdate.h"
#include "molecule.h"
#include "sys.h"
#include "vector"

class systemUpdate
{
  public:
    static void sysUpdate(sys&, double);

    static void posUpdate(sys&, double);

    static void velUpdate(sys&, double);
};

#endif // SYSTEMUPDATE_H
