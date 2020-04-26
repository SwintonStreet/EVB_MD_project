#include "keyWordVec.h"
#include "keyWord.h"

bool keyWordVec::containsKeyWord(const keyWord& inKw) const
{
    return kWM.find(inKw.getName()) != kWM.end();
}

bool keyWordVec::containsKeyWord(const std::string& name, keyWord& inKw)
{
    bool ret = (kWM.find(name) != kWM.end());
    if (ret)
    {
        inKw = kWM[name];
    }
    return ret;
}

bool keyWordVec::addKeyWord(const keyWord& inKw, bool overWrite)
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

bool keyWordVec::isOk() const
{
    bool ret = true;
    for (const auto& kw : kWM)
    {
        if (!kw.second.getOk())
        {
            ret = false;
            break;
        }
    }
    return ret;
}

unsigned int keyWordVec::size() const { return kWM.size(); }

void keyWordVec::print(std::ostream& out) const
{
    out << "================================" << '\n'
        << "=  printing put configuration  =" << '\n'
        << "================================" << '\n';
    for (const auto& kw : kWM)
    {
        const char type = kw.second.getType();
        out << "==== Key word ====" << '\n'
            << "Name : " << kw.second.getName() << '\n';
        switch (type)
        {
        case 'I':
            out << "Type : Integer" << '\n'
                << "Value: " << kw.second.getInt() << '\n';
            break;
        case 'D':
            out << "Type : Double" << '\n'
                << "Value: " << kw.second.getDou() << '\n';
            break;
        case 'B':
            out << "Type : Boolean" << '\n'
                << "Value: " << kw.second.getBoo() << '\n';
            break;

        case 'S':
            out << "Type : String" << '\n'
                << "Value: " << kw.second.getString() << '\n';
            break;
        }
    }
    out << "================================" << '\n'
        << "================================" << '\n'
        << "================================" << '\n';
}
