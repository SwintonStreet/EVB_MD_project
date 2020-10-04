
#include "systemUpdate.h"

void systemUpdate::sysUpdate(sys& inSys, double timeStep)
{
    // step 1
    // update position using
    // r = r + v dt + (f/2m) (dt^2)
    posUpdate(inSys, timeStep);

    // step 2
    // update velocity based on current forces
    // v = v + (f/2m) (dt^2)
    velUpdate(inSys, timeStep);

    // step 3
    // reset forces
    // update forces
    forceUpdate::resetForce(inSys);
    forceUpdate::forcUpdate(inSys);

    // step 4
    // update velocity based on updated forces
    // v = v + (f/2m) (dt^2)
    velUpdate(inSys, timeStep);
}

void systemUpdate::posUpdate(sys& inSys, double timeStep)
{
    for (auto& molVec : inSys.getMols())
    {
        for (auto& mol : molVec)
        {
            for (auto& atom : mol.getAtoms())
            {
                atom.setPos(atom.getPos() + timeStep * atom.getVel() +
                            ((timeStep * timeStep) / (2 * atom.getMass())) *
                                atom.getForc());
            }
        }
    }
}

void systemUpdate::velUpdate(sys& inSys, double timeStep)
{
    for (auto& molVec : inSys.getMols())
    {
        for (auto& mol : molVec)
        {
            for (auto& atom : mol.getAtoms())
            {
                atom.setVel(atom.getVel() +
                            (timeStep / (2 * atom.getMass())) * atom.getForc());
            }
        }
    }
}
