#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <fstream>

#include "treeNode.h"
#include "nodeStatistics.h"

class binaryTree
{
    public:
        //Constructor
        binaryTree(std::ifstream& inf);

        //Destructor
        ~binaryTree();

        //Functions
        void printAVL();
        void searchForKey(std::ifstream& inf);
        void searchForSubTree(binaryTree& subtree);

        //getter
        treeNode* getRoot();

    private:
        //Variables
        treeNode* root;

        //Functions
        void appendKey(int key);

};

#endif // BINARYTREE_H
