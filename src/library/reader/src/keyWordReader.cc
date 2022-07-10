#include "keyWordReader.h"

#include <fstream>
#include <memory>
#include <sstream>
#include <string>

#include "keyWord.h"
#include "keyWordVec.h"
#include "readlib.h"

using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;

namespace keyWordReader
{

keyWordVec defaultReader()
{
    keyWordVec kwv;

    ifstream defFile(keyWordReader::defaultFileName);
    string   line;
    string   word;
    string   name;
    int      lineNumber{0};

    auto errstr = [&lineNumber, &name]
    {
        return "Invalid config item:" + name + '\n' +
               "on line number: " + std::to_string(lineNumber) + '\n';
    };

    if (defFile.is_open())
    {
        int    iValue;
        double dValue;
        bool   bValue;

        while (getline(defFile, line))
        {
            // increment the line number
            lineNumber++;

            // the first letter of the line will determine
            // what config item will be passed in
            istringstream iss(line);
            iss >> word;
            iss >> name;

            switch (line[0])
            {
            case 'I':
                iss >> word;
                iValue = readlib::readINT(word, errstr());
                kwv.addKeyWord(keyWord(name, iValue), true);
                break;

            case 'D':
                iss >> word;
                dValue = readlib::readDOU(word, errstr());
                kwv.addKeyWord(keyWord(name, dValue), true);
                break;

            case 'B':
                iss >> word;
                bValue = readlib::readBOO(word, errstr());
                kwv.addKeyWord(keyWord(name, bValue), true);
                break;

            case 'S':
                iss >> word;
                kwv.addKeyWord(keyWord(name, word), true);
                break;

            default:
                // Ignore unsupported values
                break;
            }
        }
    }

    // print out the parameters to the params file
    kwv.print();

    return kwv;
}
} // namespace keyWordReader
