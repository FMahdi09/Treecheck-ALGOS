#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

#include "nodeStatistics.h"

class treeNode
{
    public:
        //Constructor
        treeNode(int key);

        //Destructor
        ~treeNode();

        //Functions
        void appendKey(int key);
        nodeStatistics getStats();
        int getMax();
        int getMin();

    private:
        //Variables
        int key;
        treeNode* leftNode;
        treeNode* rightNode;
};

#endif // TREENODE_H
