
#ifndef KEYWORD_H
#define KEYWORD_H

#include "iostream"
#include "string"
#include "vector"
#include "stdlib.h"
#include "keyWordVec.h"

class keyWordDefault;


class keyWord
{
    std::string name;
    bool        isOk;
    bool        isDefault;
    int         intValue;
    double      douValue;
    bool        booValue;
    char        Type;

    public:

    keyWord(std::string_view,int   );
    keyWord(std::string_view,double);
    keyWord(std::string_view,bool  );
    explicit keyWord(keyWordDefault);
    keyWord();

    ~keyWord() = default;

    void setValue(int);
    void setValue(double);
    void setValue(bool);

    int         getInt() const;
    double      getDou() const;
    bool        getBoo() const;
    std::string getName() const;
    bool        getOk() const;
    const char& getType() const {return Type;};
    bool        getDef() const {return isDefault;};

    // copy constructor
    explicit keyWord(const keyWord& kW) noexcept
    {
        name      = kW.name;
        intValue  = kW.intValue;
        douValue  = kW.douValue;
        booValue  = kW.booValue;
        isOk      = kW.isOk;
        isDefault = kW.isDefault;
    };

    // copy assignment operator
    keyWord& operator= (const keyWord& kW) noexcept
    {
        if (this != &kW)
        {
            name      = kW.name;
            intValue  = kW.intValue;
            douValue  = kW.douValue;
            booValue  = kW.booValue;
            isOk      = kW.isOk;
            isDefault = kW.isDefault;
        }

        return *this;
    }

    void setKeyWord(keyWordVec&        kwv,
                    const std::string& name,
                    bool               mandatory = false);

};

#endif // KEYWORD_H
