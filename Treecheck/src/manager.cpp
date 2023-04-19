#include "manager.h"

//Constructor
manager::manager()
{
}

//Functions

//main loop
void manager::start()
{
    bool run = true;

    while(run)
    {
        //stores the values of the user input as array of strings
        //0 = command, 1 = mainTree-filename, 2 = subTree-filename, 3 = checks for too many given values
        std::string input[4];

        for(int i = 0; i < 4; ++i)
        {
            std::cin >> input[i];

            if(std::cin.peek() == '\n')
            {
                break;
            }
        }

        if(input[0] == "treecheck")
        {
            //check for invalid number of parameters
            if(input[1] == "" || input[3] != "")
            {
                std::cout << "invalid number of parameters. try again.\n";

                //flush any leftover parameters out of input stream
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                mainLogic(input[1], input[2]);
            }
        }
        else
        {
            std::cout << "unknown command. try again.\n";

            //flush any leftover parameters out of input stream
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void manager::mainLogic(std::string mainTree, std::string subTree)
{
    binaryTree Tree(mainTree);

    if(Tree.getRoot() != nullptr)
    {
       Tree.getStats();
    }
}
