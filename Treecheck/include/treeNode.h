#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <algorithm>

#include "headerStats.h"

class treeNode
{
    public:
        //Constructor
        treeNode(int key);

        //Destructor
        ~treeNode();

        //Functions
        void appendKey(int key);
        nodeStats getStats();

    private:
        //Variables
        int key;
        treeNode* leftNode;
        treeNode* rightNode;
};

#endif // TREENODE_H
