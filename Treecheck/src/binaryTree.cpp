#include "binaryTree.h"

//Constructor
binaryTree::binaryTree(std::string filename)
{
    root = nullptr;

    //open file
    std::ifstream inf("data\\" + filename);

    if (!inf.is_open()) {
        std::cout << "file: \"" << filename << "\" was not found. try again\n";
        return;
    }

    //read from file
    while(!inf.eof())
    {
        int data;

        inf >> data;

        appendKey(data);
    }

    //close file
    inf.close();
}

//Destructor
binaryTree::~binaryTree()
{
    delete root;
}

//Functions

void binaryTree::appendKey(int key)
{
    if(root == nullptr)
    {
        root = new treeNode(key);
    }
    else
    {
        root->appendKey(key);
    }
}

void binaryTree::getStats()
{
    nodeStats treeStats = root->getStats();

    std::string avlStatus = treeStats.AVL == true ? "yes" : "no";

    std::cout << "AVL: " << avlStatus  << "\n";
    std::cout << "min: " << treeStats.minKey << ", max: " << treeStats.maxKey << ", avg:" << (float)treeStats.total / (float)treeStats.counter << "\n";
}

//Getter

treeNode* binaryTree::getRoot() const
{
    return root;
}
