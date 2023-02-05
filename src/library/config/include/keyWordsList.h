#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace keyWordsList
{

enum class keyWordType
{
    BOOL,
    DOUBLE,
    INT,
    STRING
};

struct keyWordDefault
{

    // set bool keyWord
    static keyWordDefault setBool(std::string inName, bool inBool)
    {
        keyWordDefault ret;
        ret.name      = std::move(inName);
        ret.kwType    = keyWordType::BOOL;
        ret.boolValue = inBool;
        return ret;
    }

    // set int keyWord
    static keyWordDefault setInt(std::string inName, int inInt)
    {
        keyWordDefault ret;
        ret.name     = std::move(inName);
        ret.kwType   = keyWordType::INT;
        ret.intValue = inInt;
        return ret;
    }

    // set double keyWord
    static keyWordDefault setDouble(std::string inName, double inDouble)
    {
        keyWordDefault ret;
        ret.name        = std::move(inName);
        ret.kwType      = keyWordType::DOUBLE;
        ret.doubleValue = inDouble;
        return ret;
    }

    // set string keyWord
    static keyWordDefault setString(std::string inName, std::string inString)
    {
        keyWordDefault ret;
        ret.name        = std::move(inName);
        ret.kwType      = keyWordType::STRING;
        ret.stringValue = std::move(inString);
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
    keyWordDefault(const keyWordDefault& rhs) = default;

    keyWordDefault() = default;

    ~keyWordDefault() = default;

    std::string name;
    keyWordType kwType{};
    bool        boolValue{};
    double      doubleValue{};
    std::string stringValue;
    int         intValue{};
};

const std::vector<keyWordDefault> keyWordList = {
    keyWordDefault::setInt("NUM_ITER", 1),
    keyWordDefault::setInt("PRINT_EVERY", 1),
    keyWordDefault::setDouble("TIME_STEP", 1),
    keyWordDefault::setString("LOG_LEVEL", "DEFAULT")};

inline bool isInKeyWordList(const std::string_view inWord)
{
    bool keyWordIsInList = false;
    for (const auto& kwD : keyWordsList::keyWordList)
    {
        if (kwD.name == inWord)
        {
            keyWordIsInList = true;
            break;
        }
    }
    return keyWordIsInList;
}

inline std::optional<keyWordDefault>
getKeyWordFromList(const std::string_view inWord)
{
    std::optional<keyWordDefault> retKeyWord;

    for (const auto& kwD : keyWordsList::keyWordList)
    {
        if (kwD.name == inWord)
        {
            retKeyWord = kwD;
            break;
        }
    }

    return retKeyWord;
}
} // namespace keyWordsList
