
#ifndef KEYWORD_H
#define KEYWORD_H

#include "iostream"
#include "string"
#include "vector"
#include "keyWordsList.h"
#include "stdlib.h"
#include "keyWordVec.h"


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
    keyWord(keyWordDefault);
    keyWord();

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

    void copyKeyWord(keyWord);

    void setKeyWord(keyWordVec&        kwv,
                    const std::string& name,
                    bool               mandatory = false);

};

#endif // KEYWORD_H
