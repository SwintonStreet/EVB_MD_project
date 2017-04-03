#ifndef TWOBONDLOOP_H
#define TWOBONDLOOP_H

#include <vector>
#include <string>
#include "atom.h"
#include "sys.h"
#include "twoAtomBonds.h"



namespace twoBondLoop
{
    double calcEngForTwoBond(std::vector<twoBonds_t>&,
                             std::vector<atom>&);

    void calcEngForSysTwoBond(sys&);
}

#endif // TWOBONDLOOP_H
