#include "keyWordVec.h"
#include "keyWord.h"

bool keyWordVec::containsKeyWord(keyWord& inKw)
{
    auto it = kWM.find(inKw.getName());
    return it != kWM.end();
}

bool keyWordVec::containsKeyWord(const std::string& name,
                                 keyWord&           inKw)
{
    auto it  = kWM.find(name);
    bool ret = (it != kWM.end());
    if (ret)
    {
        inKw = kWM[name];
    }
    return ret;
}

bool keyWordVec::addKeyWord(keyWord inKw,
                            bool    overWrite)
{
    bool ok = true;
    if (containsKeyWord(inKw))
    {
        if (overWrite)
        {
            kWM[inKw.getName()] = inKw;
        }
        else
        {
            ok = false;
        }
    }
    else
    {
        kWM[inKw.getName()] = inKw;
    }
    return ok;
}

bool keyWordVec::isOk()
{
    bool ret = true;
    for (auto& kw : kWM)
    {
        if (! kw.second.getOk())
        {
            ret = false;
            break;
        }
    }
    return ret;
}

unsigned int keyWordVec::size()
{
    return kWM.size();
}
