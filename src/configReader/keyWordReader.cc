#include "keyWordReader.h"
#include "readlib.h"
#include "keyWordVec.h"
#include "keyWord.h"
#include "fstream"
#include "sstream"

bool keyWordReader::defaultReader(keyWordVec&  kwv) const
{
    std::ifstream defFile(keyWordReader::defaultFileName);
    std::string line, word, name;
    int         iValue;
    double      dValue;
    bool        bValue;
    int         lineNumber{0};

    auto errstr = [&lineNumber,&name] () -> std::string
    {
        return "Invalid config item:" + name + '\n' +
               "on line number: " + std::to_string(lineNumber) + '\n';
    };

    if (defFile.is_open())
    {
        while (std::getline(defFile,line))
        {
            // increment the line number
            lineNumber++;

            // the first letter of the line will determine
            // what config item will be passed in
            std::istringstream iss(line);
            iss >> word;
            iss >> name;

            switch ( line[0] )
            {
                case 'I':
                    iss >> word;
                    iValue = readlib::readINT(word,errstr());
                    kwv.addKeyWord(keyWord(name,iValue),true);
                    break;

                case 'D':
                    iss >> word;
                    dValue = readlib::readDOU(word,errstr());
                    kwv.addKeyWord(keyWord(name,dValue),true);
                    break;

                case 'B':
                    iss >> word;
                    bValue = readlib::readBOO(word,errstr());
                    kwv.addKeyWord(keyWord(name,bValue),true);
                    break;

                default:
                    // Ignore unsupported values
                    break;
            }
        }
    }

    return kwv.isOk();
}
