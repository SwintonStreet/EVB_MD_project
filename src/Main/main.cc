// main - the thing that runs!

#include "iostream"
#include "fstream"
#include "molReader.h"
#include "xyzReader.h"
#include "evb_system.h"
#include "mainLoop.h"
#include "molecule.h"
#include "keyWordReader.h"
#include "vector"
#include "keyWordVec.h"

int main ()
{
    std::cout << "Hello world!!" << std::endl;
    keyWordVec kwVec;

    // main output fileName
    std::ofstream mainOutputFile;
    mainOutputFile.open("Run");


    keyWordReader test1 = keyWordReader();
    test1.defaultReader(kwVec);

    std::cout << "finished!!" << kwVec.size() << std::endl;
    kwVec.print(mainOutputFile);

    keyWord test = keyWord();
    test.setKeyWord(kwVec,"KEY1");

    std::cout << "value is " << test.getInt() << std::endl;

    molReader test2 = molReader();
    xyzReader test3 = xyzReader();

    std::vector<molecule> defMol = test2.MolConfReader();

    sys testSys = test3.readXyzFile(defMol);

    testSys.printSysPos(std::cout);
    // print out system information
    testSys.printSysPos(mainOutputFile);

    mainLoop mL = mainLoop(kwVec,
                           testSys);

    mL.runLoop(mainOutputFile);


    std::cout << "==--END-OF-PROGRAM--==\n";

    mainOutputFile.close();


    //std::cout << "testboo is " << testboo << std::endl;

    return 0;
}
