#include "keyWordReader.h"

#include <fstream>
#include <memory>
#include <sstream>
#include <string>

#include "defaultFileAccess.h"
#include "keyWord.h"
#include "keyWordVec.h"
#include "readlib.h"

using std::ifstream;
using std::istringstream;
using std::make_shared;
using std::nullopt;
using std::optional;
using std::shared_ptr;
using std::string;

using utils::defaultFileAccess;
using utils::fileAccess;

namespace reader
{

keyWordReader::keyWordReader() :
    keyWordReader(make_shared<defaultFileAccess>(reader::defaultFileName))
{
}

keyWordReader::keyWordReader(shared_ptr<fileAccess> fileAccess) :
    fileAccess_{std::move(fileAccess)}
{
}

keyWordVec keyWordReader::defaultReader()
{
    keyWordVec kwv;

    string word;
    string name;
    int    lineNumber{0};

    auto errstr = [&lineNumber, &name]
    {
        return "Invalid config item:" + name + '\n' +
               "on line number: " + std::to_string(lineNumber) + '\n';
    };

    int    iValue{0};
    double dValue{0.0};
    bool   bValue{false};

    for (optional<string> line = fileAccess_->getLine();
         line != nullopt; // continue while we have lines
         line = fileAccess_->getLine())
    {
        // Scheme is
        //
        // <type> <name> <value>
        //
        // <type> : single letter denoting the type, either
        //          * I Integer
        //          * D Double
        //          * B Boolean
        //          * S String
        //
        // Example
        // I Key1 10
        //
        // increment the line number
        lineNumber++;

        if (line->empty() || line->find_first_not_of(' ') == string::npos)
        {
            // string is empty or just has white space, ignore
            continue;
        }

        // the first letter of the line will determine
        // what config item will be passed in
        istringstream iss(*line);
        iss >> word;
        iss >> name;

        switch ((*line)[0])
        {
        case '#':
            // ignore comments
            break;
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
        {
            string sLine;
            string sVal;
            while (iss >> sVal)
            {
                if (!sLine.empty())
                {
                    sLine += ' ';
                }
                sLine += sVal;
            }
            kwv.addKeyWord(keyWord(name, std::move(sLine)), true);
        }
        break;

        default:
            // Ignore unsupported values
            string configError{"Failed to read config file '"};
            configError += fileAccess_->getFileName();
            configError += "'.";

            throw configReadError(configError);
        }
    }

    // print out the parameters to the params file
    kwv.print();

    return kwv;
}

} // namespace reader
