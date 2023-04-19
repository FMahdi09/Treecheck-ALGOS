#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include<limits>

#include "binaryTree.h"

class manager
{
    public:
        //Constructor
        manager();

        //Functions
        void start();

    private:
        //Functions
        void mainLogic(std::string mainTree, std::string subTree);
};

#endif // MANAGER_H
