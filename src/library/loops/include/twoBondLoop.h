#ifndef TWOBONDLOOP_H
#define TWOBONDLOOP_H

#include <string>
#include <vector>

#include "atom.h"
#include "sys.h"
#include "twoAtomBonds.h"

namespace twoBondLoop
{
double calcEngForTwoBond(const std::vector<twoBonds_t>&, std::vector<atom>&);

void calcEngForSysTwoBond(sys&);
} // namespace twoBondLoop

#endif // TWOBONDLOOP_H
