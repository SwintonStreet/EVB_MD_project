// atom info

#include "atomConfig.h"

atomConfig::atomConfig(char*  inName,
                       double inx,
                       double iny,
                       double inz)
{
    acName = inName;
    double inXyz [3] = {inx,iny,inz};
    xyz = inXyz;
}
