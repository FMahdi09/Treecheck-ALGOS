#include <iostream>
#include <fstream>
#include <algorithm>

#include "binaryTree.h"

int main(int argc, char* argv[])
{
    std::ifstream inf_main, inf_sub;

    switch(argc)
    {
        case 2:
            inf_main.open(argv[1]);

            if(inf_main.is_open())
            {
                binaryTree mainTree(inf_main);

                mainTree.printAVL();
            }
            else
            {
                std::cout << "invalid file path.\n";
                return 2;
            }
        break;
        case 3:
            inf_main.open(argv[1]);
            inf_sub.open(argv[2]);

            if(inf_main.is_open() && inf_sub.is_open())
            {
                binaryTree mainTree(inf_main);

                int lineCount = std::count(std::istreambuf_iterator<char>(inf_sub), std::istreambuf_iterator<char>(), '\n');

                //set "courser" to beginning of file
                inf_sub.clear();
                inf_sub.seekg(0);

                if(lineCount == 0)
                {
                    mainTree.searchForKey(inf_sub);
                }
                else
                {
                    binaryTree subTree(inf_sub);

                    mainTree.searchForSubTree(subTree);
                }
            }
            else
            {
                std::cout << "invalid file path.\n";
                return 2;
            }
        break;
        default:
            std::cout << "invalid number of parameters.\n";
            return 1;
    }

    return 0;
}
