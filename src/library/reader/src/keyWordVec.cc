#include "keyWordVec.h"

#include <algorithm>
#include <memory>
#include <optional>
#include <string>

#include "keyWord.h"
#include "logger.h"

using std::optional;
using std::string_view;

namespace reader
{

[[nodiscard]] bool keyWordVec::containsKeyWord(const keyWord& inKw) const
{
    return kWM_.contains(inKw.getName());
}

bool keyWordVec::containsKeyWord(const std::string& name, keyWord& inKw) const
{
    const bool ret = kWM_.contains(name);
    if (ret)
    {
        inKw = kWM_.at(name);
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
            kWM_[inKw.getName()] = inKw;
        }
        else
        {
            ok = false;
        }
    }
    else
    {
        kWM_[inKw.getName()] = inKw;
    }
    return ok;
}

bool keyWordVec::isOk() const
{
    return std::any_of(kWM_.begin(),
                       kWM_.end(),
                       [](const auto& kw) { return kw.second.getOk(); });
}

size_t keyWordVec::size() const { return kWM_.size(); }

void keyWordVec::print() const
{
    logger::paramFile << "================================\n"
                         "=  printing put configuration  =\n"
                         "================================\n";
    for (const auto& kw : kWM_)
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

optional<keyWord> keyWordVec::at(const std::string& name) const
{
    try
    {
        return kWM_.at(name);
    }
    catch (const std::out_of_range& e)
    {
        return std::nullopt;
    }
};

} // namespace reader
