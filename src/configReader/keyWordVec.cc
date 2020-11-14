#include "keyWordVec.h"
#include "keyWord.h"
#include "logger.h"
#include <algorithm>

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
    return std::any_of(kWM.begin(), kWM.end(), [](const auto& kw) {
        return kw.second.getOk();
    });
}

unsigned int keyWordVec::size() const { return kWM.size(); }

void keyWordVec::print() const
{
    logger::paramFile << "================================\n"
                         "=  printing put configuration  =\n"
                         "================================\n";
    for (const auto& kw : kWM)
    {
        const char type = kw.second.getType();
        logger::paramFile << "==== Key word ====\n"
                             "Name : "
                          << kw.second.getName() << '\n';
        switch (type)
        {
        case 'I':
            logger::paramFile << "Type : Integer\n"
                                 "Value: "
                              << kw.second.getInt() << '\n';
            break;

        case 'D':
            logger::paramFile << "Type : Double\n"
                                 "Value: "
                              << kw.second.getDou() << '\n';
            break;

        case 'B':
            logger::paramFile << "Type : Boolean\n"
                                 "Value: "
                              << kw.second.getBoo() << '\n';
            break;

        case 'S':
            logger::paramFile << "Type : String\n"
                                 "Value: "
                              << kw.second.getString() << '\n';
            break;
        }
    }
    logger::paramFile << "================================\n"
                         "================================\n"
                         "================================\n";
}
