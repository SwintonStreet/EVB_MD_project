#include "string"
#include "vector"
#include "optional"

enum keyWordType {BOOL, DOUBLE, INT};

struct keyWordDefault
{
    keyWordDefault() = default;
    ~keyWordDefault() = default;

    std::string name;
    keyWordType kwType;
    bool        boolValue;
    double      doubleValue;
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
    keyWordDefault (const keyWordDefault& rhs)
    {
        name        = rhs.name;
        kwType      = rhs.kwType;
        boolValue   = rhs.boolValue;
        intValue    = rhs.intValue;
        doubleValue = rhs.doubleValue;
    }
};

class keyWordsList
{
    static const std::vector<keyWordDefault> keyWordList;
    public:

    static bool isInKeyWordList(const std::string_view inWord)
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

    static std::optional<keyWordDefault>
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
};

