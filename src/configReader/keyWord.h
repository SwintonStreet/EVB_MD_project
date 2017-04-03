
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

    public:

    keyWord(std::string,int   );
    keyWord(std::string,double);
    keyWord(std::string,bool  );
    keyWord(keyWordDefault);
    keyWord();

    void setValue(int);
    void setValue(double);
    void setValue(bool);

    int          getInt();
    double       getDou();
    bool         getBoo();
    std::string  getName();
    bool         getOk();
    bool         getDef() {return isDefault;};

    void copyKeyWord(keyWord);

    void setKeyWord(keyWordVec&        kwv,
                    const std::string& name,
                    bool               mandatory = false);

};

#endif // KEYWORD_H
