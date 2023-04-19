#include <iostream>
#include <fstream>

#include "binaryTree.h"

int main(int argc, char* argv[])
{
    std::ifstream inf;

    switch(argc)
    {
        case 2:
            inf.open(argv[1]);

            if(inf.is_open())
            {
                binaryTree mainTree(inf);

                mainTree.printAVL();
            }
            else
            {
                std::cout << "invalid file path: \"" << argv[1] << "\"\n";
                return 2;
            }
        break;
        case 3: ;
        break;
        default:
            std::cout << "invalid number of parameters.\n";
            return 1;
    }

    return 0;
}
