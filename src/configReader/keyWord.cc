
#include "keyWord.h"

keyWord::keyWord()
{
    isDefault = true;
}

keyWordDefault dummyKwD;

keyWord::keyWord(std::string inName, int inInt)
{
    name      = inName;
    intValue  = inInt;
    isOk      = keyWordsList::isInKeyWordList(inName,
                                              dummyKwD);
    Type      = 'I';
    isDefault = false;
}


keyWord::keyWord(std::string inName, double inDou)
{
    name     = inName;
    douValue = inDou;
    isOk     = keyWordsList::isInKeyWordList(inName,
                                             dummyKwD);
    Type      = 'D';
    isDefault = false;
}

keyWord::keyWord(std::string inName, bool inBoo)
{
    name      = inName;
    booValue  = inBoo;
    isOk      = keyWordsList::isInKeyWordList(inName,
                                              dummyKwD);
    Type      = 'B';
    isDefault = false;
}

keyWord::keyWord(keyWordDefault kwD)
{
    name      = kwD.name;
    isDefault = true;
    switch(kwD.kwType)
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
    isOk      = keyWordsList::isInKeyWordList(name,
                                              dummyKwD);
}

void keyWord::setValue(int inInt)
{
    intValue = inInt;
}

void keyWord::setValue(double inDou)
{
    douValue = inDou;
}

void keyWord::setValue(bool inBoo)
{
    booValue = inBoo;
}


int keyWord::getInt()
{
    return intValue;
}

double keyWord::getDou()
{
    return douValue;
}

bool keyWord::getBoo()
{
    return booValue;
}

std::string keyWord::getName()
{
    return name;
}

bool keyWord::getOk()
{
    return isOk;
}

void keyWord::setKeyWord(keyWordVec&        kwv,
                         const std::string& keyName,
                         bool               mandatory)
{
    keyWord        retKw = keyWord();
    keyWordDefault kwD   = keyWordDefault();

    if (kwv.containsKeyWord(keyName,retKw))
    {
    }
    else if (keyWordsList::isInKeyWordList(keyName,kwD))
    {
        retKw = keyWord(kwD);
    }
    else if (mandatory)
    {
        // if the look up is mandatory and the field hasn't
        // been found then throw an error!!!
        std::cerr << "Failed to find mandatory field : " <<
                     keyName  <<
                     "\n";
        exit(EXIT_FAILURE);
    }

    (*this) = retKw;
    //this->copyKeyWord(retKw);
}

void keyWord::copyKeyWord(keyWord kW)
{
    name      = kW.name;
    intValue  = kW.intValue;
    douValue  = kW.douValue;
    booValue  = kW.booValue;
    isOk      = kW.isOk;
    isDefault = kW.isDefault;
}
