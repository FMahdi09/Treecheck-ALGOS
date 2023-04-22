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

        bool searchForKey(int key);
        void printPathTo(int key);

        bool searchForSubTree(treeNode* subRoot);

        nodeStatistics getStats();
        int getMax();
        int getMin();

        //getter
        int getKey();
        treeNode* getLeftNode();
        treeNode* getRightNode();

    private:
        //Variables
        int key;
        treeNode* leftNode;
        treeNode* rightNode;
};

#endif // TREENODE_H
