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
nodeStats treeNode::getStats()
{
    nodeStats rightStats, leftStats, curStats;

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

    //set max key value of the current subtree
    curStats.maxKey = std::max(key, std::max(rightStats.maxKey, leftStats.maxKey));

    //set min key value of the current subtree
    curStats.minKey = std::min(key, std::min(rightStats.minKey, leftStats.minKey));

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
