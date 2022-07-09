#ifndef TWOBONDLOOP_H
#define TWOBONDLOOP_H

#include "atom.h"
#include "sys.h"
#include "twoAtomBonds.h"
#include <string>
#include <vector>

namespace twoBondLoop
{
double calcEngForTwoBond(const std::vector<twoBonds_t>&, std::vector<atom>&);

void calcEngForSysTwoBond(sys&);
} // namespace twoBondLoop

#endif // TWOBONDLOOP_H
