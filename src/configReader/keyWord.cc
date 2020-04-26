
#include "keyWord.h"
#include "keyWordsList.h"
#include "optional"

keyWord::keyWord() { isDefault = true; }

keyWord::keyWord(std::string_view inName, int inInt)
    : name{inName}, intValue{inInt}
{
    isOk      = keyWordsList::isInKeyWordList(inName);
    Type      = 'I';
    isDefault = false;
}

keyWord::keyWord(std::string_view inName, double inDou)
    : name{inName}, douValue{inDou}
{
    isOk      = keyWordsList::isInKeyWordList(inName);
    Type      = 'D';
    isDefault = false;
}

keyWord::keyWord(std::string_view inName, bool inBoo)
    : name{inName}, booValue{inBoo}
{
    isOk      = keyWordsList::isInKeyWordList(inName);
    Type      = 'B';
    isDefault = false;
}

keyWord::keyWord(std::string_view inName, std::string_view inString)
    : name{inName}, sValue{inString}
{
    isOk      = keyWordsList::isInKeyWordList(inName);
    Type      = 'S';
    isDefault = false;
}

keyWord::keyWord(const keyWordDefault& kwD)
{
    name      = kwD.name;
    isDefault = true;
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

    isOk = keyWordsList::isInKeyWordList(name);
}

void keyWord::setValue(int inInt) { intValue = inInt; }

void keyWord::setValue(double inDou) { douValue = inDou; }

void keyWord::setValue(bool inBoo) { booValue = inBoo; }

int keyWord::getInt() const { return intValue; }

double keyWord::getDou() const { return douValue; }

bool keyWord::getBoo() const { return booValue; }

std::string keyWord::getString() const { return sValue; }

std::string keyWord::getName() const { return name; }

bool keyWord::getOk() const { return isOk; }

void keyWord::setKeyWord(keyWordVec&        kwv,
                         const std::string& keyName,
                         bool               mandatory)
{
    keyWord        retKw;
    keyWordDefault kwD;

    if (kwv.containsKeyWord(keyName, retKw))
    {
    }
    else if (const auto& defKw = keyWordsList::getKeyWordFromList(keyName);
             defKw)
    {
        retKw = keyWord(defKw.value());
    }
    else if (mandatory)
    {
        // if the look up is mandatory and the field hasn't
        // been found then throw an error!!!
        std::cerr << "Failed to find mandatory field : " << keyName << '\n';
        exit(EXIT_FAILURE);
    }

    (*this) = retKw;
}
