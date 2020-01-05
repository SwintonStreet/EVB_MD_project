

#include "keyWordReader.h"

keyWordReader::keyWordReader()
{
}

//template<typename keyWord>

bool keyWordReader::defaultReader(keyWordVec&  kwv)
{

    std::string line;
    bool isOk = true;

    std::ifstream defFile(keyWordReader::defaultFileName);
    std::string word, name;
    int         iValue;
    double      dValue;
    bool        bValue;

    if (defFile.is_open())
    {
        while (std::getline(defFile,line))
        {
            // the first letter of the line will determine
            // what config item will be passed in
            std::istringstream iss(line);
            iss >> word;
            iss >> name;

            switch ( line[0] )
            {
                case 'I':
                    iss >> word;
                    iValue = readlib::readINT(word,
                                              "Invalid config item:" + name + "\n");
                    kwv.addKeyWord(keyWord(name,iValue),true);
                    break;

                case 'D':
                    iss >> word;
                    dValue = readlib::readDOU(word,
                                              "Invalid config item:" + name + "\n");
                    std::cout << "double " << dValue << std::endl;
                    kwv.addKeyWord(keyWord(name,dValue),true);
                    break;

                case 'B':
                    iss >> word;
                    bValue = readlib::readBOO(word,
                                              "Invalid config item:" + name + "\n");
                    kwv.addKeyWord(keyWord(name,bValue),true);
                    break;

            }
        }
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    isOk = kwv.isOk();

    return isOk;
}
