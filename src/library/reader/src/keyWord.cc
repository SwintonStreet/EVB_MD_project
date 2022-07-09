#include "keyWord.h"

#include <iostream>
#include <string>
#include <string_view>

#include "keyWordsList.h"

using std::cerr;
using std::string;
using std::string_view;

keyWord::keyWord(string_view inName, int inInt) :
    name{inName}, isOk{keyWordsList::isInKeyWordList(inName)}, isDefault{false},
    intValue{inInt}, Type{'I'}
{
}

keyWord::keyWord(string_view inName, double inDou) :
    name{inName}, isOk{keyWordsList::isInKeyWordList(inName)}, isDefault{false},
    douValue{inDou}, Type{'D'}
{
}

keyWord::keyWord(string_view inName, bool inBoo) :
    name{inName}, isOk{keyWordsList::isInKeyWordList(inName)}, isDefault{false},
    booValue{inBoo}, Type{'B'}
{
}

keyWord::keyWord(string_view inName, string_view inString) :
    name{inName}, isOk{keyWordsList::isInKeyWordList(inName)}, isDefault{false},
    sValue{inString}, Type{'B'}
{
}

keyWord::keyWord(const keyWordDefault& kwD) :
    name{kwD.name}, isOk{keyWordsList::isInKeyWordList(name)}, isDefault{true}
{
    switch (kwD.kwType)
    {
    case BOOL:
        booValue = kwD.boolValue;
        Type     = 'B';
        break;
    case INT:
        intValue = kwD.intValue;
        Type     = 'I';
        break;
    case DOUBLE:
        douValue = kwD.doubleValue;
        Type     = 'D';
        break;
    default:
        isDefault = false;
        break;
    }
}

void keyWord::setValue(int inInt) { intValue = inInt; }

void keyWord::setValue(double inDou) { douValue = inDou; }

void keyWord::setValue(bool inBoo) { booValue = inBoo; }

int keyWord::getInt() const { return intValue; }

double keyWord::getDou() const { return douValue; }

bool keyWord::getBoo() const { return booValue; }

string keyWord::getString() const { return sValue; }

string keyWord::getName() const { return name; }

bool keyWord::getOk() const { return isOk; }

keyWord
keyWord::getKeyWord(keyWordVec& kwv, const string& keyName, bool mandatory)
{
    keyWord        retKw;
    keyWordDefault kwD;

    // first attempt to get the value from the read values
    if (kwv.containsKeyWord(keyName, retKw))
    {
    }
    // if no value is in the config, check if we have default values and
    // assign that
    else if (const auto& defKw = keyWordsList::getKeyWordFromList(keyName);
             defKw)
    {
        retKw = keyWord(defKw.value());
    }
    // if the look up is mandatory and the field hasn't
    // been found then throw an error!!!
    else if (!kwv.containsKeyWord(keyName, retKw) && mandatory)
    {
        cerr << "Failed to find mandatory field : " << keyName << '\n';
        exit(EXIT_FAILURE);
    }

    return retKw;
}
