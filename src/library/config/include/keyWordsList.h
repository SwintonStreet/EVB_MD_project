#ifndef KEYWORDSLIST_H
#define KEYWORDSLIST_H

#include "string"
#include "vector"
#include "optional"

enum keyWordType {BOOL, DOUBLE, INT, STRING};

struct keyWordDefault
{
    std::string name;
    keyWordType kwType;
    bool        boolValue;
    double      doubleValue;
    std::string stringValue;
    int         intValue;

    // set bool keyWord
    static keyWordDefault setBool(std::string inName,
                                  bool        inBool)
    {
        keyWordDefault ret;
        ret.name      = inName;
        ret.kwType    = BOOL;
        ret.boolValue = inBool;
        return ret;
    }

    // set int keyWord
    static keyWordDefault setInt(std::string inName,
                                 int         inInt)
    {
        keyWordDefault ret;
        ret.name     = inName;
        ret.kwType   = INT;
        ret.intValue = inInt;
        return ret;
    }

    // set double keyWord
    static keyWordDefault setDouble(std::string inName,
                                    double      inDouble)
    {
        keyWordDefault ret;
        ret.name        = inName;
        ret.kwType      = DOUBLE;
        ret.doubleValue = inDouble;
        return ret;
    }

    // set string keyWord
    static keyWordDefault setString(std::string inName,
                                    std::string inString)
    {
        keyWordDefault ret;
        ret.name        = inName;
        ret.kwType      = STRING;
        ret.stringValue = inString;
        return ret;
    }

    /**
     * Copy assignment
     */
    keyWordDefault& operator=(const keyWordDefault& rhs)
    {
        // do not self copy!
        if (this != &rhs)
        {
            name        = rhs.name;
            kwType      = rhs.kwType;
            boolValue   = rhs.boolValue;
            intValue    = rhs.intValue;
            doubleValue = rhs.doubleValue;
        }

        return *this;
    }

    /**
     * Copy operator
     */
    keyWordDefault (const keyWordDefault& rhs):
        name        {rhs.name},
        kwType      {rhs.kwType},
        boolValue   {rhs.boolValue},
        doubleValue {rhs.doubleValue},
        stringValue {rhs.stringValue},
        intValue    {rhs.intValue}
    {
    }

    keyWordDefault (): name        {},
                       kwType      {},
                       boolValue   {},
                       doubleValue {},
                       stringValue {},
                       intValue    {}
    {
    }
    ~keyWordDefault() = default;

};

namespace keyWordsList
{
    const std::vector<keyWordDefault> keyWordList =
    {
        keyWordDefault::setInt("NUM_ITER",1),
        keyWordDefault::setInt("PRINT_EVERY",1),
        keyWordDefault::setDouble("TIME_STEP",1),
        keyWordDefault::setString("LOG_LEVEL","DEFAULT")
    };

    bool isInKeyWordList(const std::string_view inWord)
    {
        bool keyWordIsInList = false;
        for (const auto& kwD : keyWordsList::keyWordList)
        {
            if ( kwD.name.compare(inWord) != 0)
            {
                keyWordIsInList = true;
                break;
            }
        }
        return keyWordIsInList;
    }

    std::optional<keyWordDefault>
                  getKeyWordFromList(const std::string_view inWord)
    {
        std::optional<keyWordDefault> retKeyWord;

        for (const auto& kw : keyWordsList::keyWordList)
        {
            if ( kw.name.compare(inWord) != 0)
            {
                retKeyWord = kw;
                break;
            }
        }

        return retKeyWord;
    }
}

#endif // KEYWORDSLIST_H
