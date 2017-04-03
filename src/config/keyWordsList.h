#include "string"
#include "vector"

enum keyWordType {BOOL, DOUBLE, INT};

struct keyWordDefault
{
    std::string name;
    keyWordType kwType;
    bool        boolValue;
    double      doubleValue;
    int         intValue;

    // set bool keyWord
    static keyWordDefault setBool(std::string inName, bool inBool)
    {
        keyWordDefault ret;
        ret.name      = inName;
        ret.kwType    = BOOL;
        ret.boolValue = inBool;
        return ret;
    }

    // set int keyWord
    static keyWordDefault setInt(std::string inName, int inInt)
    {
        keyWordDefault ret;
        ret.name     = inName;
        ret.kwType   = INT;
        ret.intValue = inInt;
        return ret;
    }

    // set double keyWord
    static keyWordDefault setDouble(std::string inName, double inDouble)
    {
        keyWordDefault ret;
        ret.name        = inName;
        ret.kwType      = DOUBLE;
        ret.doubleValue = inDouble;
        return ret;
    }
};

class keyWordsList
{
    static const std::vector<keyWordDefault> keyWordList;
    static const keyWordDefault kwD;
    public:

    static bool isInKeyWordList(std::string     inWord,
                                keyWordDefault& inKwD)
    {
        bool test = false;
        for (auto kwD : keyWordsList::keyWordList)
        {
            if ( kwD.name.compare(inWord) != 0)
            {
                test = true;
                inKwD = kwD;
                break;
            }
        }
        return test;
    }

};

