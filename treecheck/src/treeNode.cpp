#include "treeNode.h"

//Constructor
treeNode::treeNode(int key)
{
    this->key = key;
    leftNode = nullptr;
    rightNode = nullptr;
}

//Destructor
treeNode::~treeNode()
{
    delete leftNode;
    delete rightNode;
}

//Functions

void treeNode::appendKey(int key)
{
    if(this->key > key)
    {
        if(leftNode == nullptr)
        {
            leftNode = new treeNode(key);
        }
        else
        {
            leftNode->appendKey(key);
        }
    }
    else if(this-> key < key)
    {
        if(rightNode == nullptr)
        {
            rightNode = new treeNode(key);
        }
        else
        {
            rightNode->appendKey(key);
        }
    }
}

//checks if AVL-conditions are met
//returns statistics about the current node and its subtree to the node above
nodeStatistics treeNode::getStats()
{
    nodeStatistics rightStats, leftStats, curStats;

    //get statistics of the subNodes
    //if subNode does not exists use default values (listed in headerStats.h)
    if(rightNode != nullptr)
    {
        rightStats = rightNode->getStats();
    }

    if(leftNode != nullptr)
    {
        leftStats = leftNode->getStats();
    }

    //set max depth of the current subtree
    curStats.depth = rightStats.depth > leftStats.depth ? rightStats.depth + 1 : leftStats.depth + 1;

    curStats.total += key + leftStats.total + rightStats.total;
    curStats.counter += leftStats.counter + rightStats.counter + 1;

    curStats.AVL = rightStats.AVL && leftStats.AVL ? true : false;

    int AVLbalance = rightStats.depth - leftStats.depth;

    if(AVLbalance < -1 || AVLbalance > 1)
    {
        std::cout << "bal(" << key << ") = " << AVLbalance << " (AVL violation!)\n";
        curStats.AVL = false;
    }
    else
    {
        std::cout << "bal(" << key << ") = " << AVLbalance << "\n";
    }

    return curStats;
}

int treeNode::getMax()
{
    if(rightNode != nullptr)
    {
        return rightNode->getMax();
    }

    return key;
}

int treeNode::getMin()
{
    if(leftNode != nullptr)
    {
        return leftNode->getMin();
    }

    return key;
}


//searches for key in given Tree
//of the key exists returns true else false
bool treeNode::searchForKey(int key)
{
    if(this->key > key)
    {
        if(leftNode == nullptr)
        {
            return false;
        }
        else
        {
            return leftNode->searchForKey(key);
        }
    }
    else if(this-> key < key)
    {
        if(rightNode == nullptr)
        {
            return false;
        }
        else
        {
            return rightNode->searchForKey(key);
        }
    }

    return true;
}

void treeNode::printPathTo(int key)
{
    std::cout << this->key;

    if(this->key > key)
    {
        if(leftNode != nullptr)
        {
            std::cout << ", ";
            leftNode->printPathTo(key);
        }
    }
    else if(this-> key < key)
    {
        if(rightNode != nullptr)
        {
            std::cout << ", ";
            rightNode->printPathTo(key);
        }
    }
}

bool treeNode::searchForSubTree(treeNode* subRoot)
{
    //if the value in the given Node in the mainTree is
    //equivalent to the given Node of the subTree
    //repeat the function for both children-nodes of the subTree (if they exist)
    if(key == subRoot->getKey())
    {
        bool rightSubTree, leftSubTree;

        if(subRoot->getRightNode() == nullptr)
        {
            rightSubTree = true;
        }
        else if(rightNode == nullptr && subRoot->getRightNode() != nullptr)
        {
            rightSubTree = false;
        }
        else
        {
            rightSubTree = rightNode->searchForSubTree(subRoot->getRightNode());
        }

        if(subRoot->getLeftNode() == nullptr)
        {
            leftSubTree = true;
        }
        else if(leftNode == nullptr && subRoot->getLeftNode() != nullptr)
        {
            leftSubTree = false;
        }
        else
        {
            leftSubTree = leftNode->searchForSubTree(subRoot->getLeftNode());
        }

        if(leftSubTree && rightSubTree)
        {
            return true;
        }

        return false;
    }

    //search for node in mainTree, with the same value as the given
    //node in subTree
    if(this->key > subRoot->getKey())
    {
        if(leftNode == nullptr)
        {
            return false;
        }
        else
        {
            return leftNode->searchForSubTree(subRoot);
        }
    }
    else if(this->key < subRoot->getKey())
    {
        if(rightNode == nullptr)
        {
            return false;
        }
        else
        {
            return rightNode->searchForSubTree(subRoot);
        }
    }

    return false;
}

//Getter

int treeNode::getKey()
{
    return key;
}

treeNode* treeNode::getLeftNode()
{
    return leftNode;
}

treeNode* treeNode::getRightNode()
{
    return rightNode;
}
