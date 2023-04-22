#include "binaryTree.h"

//Constructor
binaryTree::binaryTree(std::ifstream& inf)
{
    root = nullptr;

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

void binaryTree::printAVL()
{
    nodeStatistics treeStats = root->getStats();

    int maxKey = root->getMax();
    int minKey = root->getMin();

    std::string avlStatus = treeStats.AVL == true ? "yes" : "no";

    std::cout << "AVL: " << avlStatus << "\n"
              << "min: " << minKey << ", max: " << maxKey << ", avg: " << (float)treeStats.total / (float)treeStats.counter << "\n";
}

void binaryTree::searchForKey(std::ifstream& inf)
{
    int key;

    //read from file
    inf >> key;

    //close file
    inf.close();

    bool keyFound = root->searchForKey(key);

    if(keyFound)
    {
        std::cout << key << " found ";
        root->printPathTo(key);
        std::cout << std::endl;
    }
    else
    {
        std::cout << key << " not found!\n";
    }
}

void binaryTree::searchForSubTree(binaryTree& subTree)
{
    bool treeFound = root->searchForSubTree(subTree.getRoot());

    if(treeFound)
    {
        std::cout << "Subtree found!\n";
    }
    else
    {
        std::cout << "Subtree not found!\n";
    }
}


//Getter

treeNode* binaryTree::getRoot()
{
    return root;
}
