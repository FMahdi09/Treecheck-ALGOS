#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <fstream>

#include "headerStats.h"
#include "treeNode.h"

class binaryTree
{
    public:
        //Constructor
        binaryTree(std::string filename);

        //Destructor
        ~binaryTree();

        //Functions
        void getStats();

        //Getter
        treeNode* getRoot() const;

    private:
        //Variables
        treeNode* root;

        //Functions
        void appendKey(int key);
};

#endif // BINARYTREE_H
