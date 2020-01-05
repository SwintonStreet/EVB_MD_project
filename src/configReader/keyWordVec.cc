#include "keyWordVec.h"
#include "keyWord.h"

bool keyWordVec::containsKeyWord(keyWord& inKw)
{
    return kWM.find(inKw.getName()) != kWM.end();
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

void keyWordVec::print(std::ofstream& out)
{
    out << "================================" << std::endl
        << "=  printing put configuration  =" << std::endl
        << "================================" << std::endl;
    for (auto& kw : kWM)
    {
        const char type = kw.second.getType();
        out << "==== Key word ===="             << std::endl
            << "Name : " << kw.second.getName() << std::endl;
        switch (type)
        {
            case 'I':
                out << "Type : Integer"                << std::endl
                    << "Value: " << kw.second.getInt() << std::endl;
                break;
            case 'D':
                out << "Type : Double"                 << std::endl
                    << "Value: " << kw.second.getDou() << std::endl;
                break;
            case 'B':
                out << "Type : Boolean"                << std::endl
                    << "Value: " << kw.second.getBoo() << std::endl;
                break;
        }
    }
    out << "================================" << '\n'
        << "================================" << '\n'
        << "================================" << '\n';
}
