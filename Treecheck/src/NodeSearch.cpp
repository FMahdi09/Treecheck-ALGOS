#include "NodeSearch.h"

NodeSearch::NodeSearch()
{
    //ctor
}

NodeSearch::~NodeSearch()
{
    //dtor
}

bool NodeSearch::isPresent(Pointer für den Baum (treeNode* root), int value, std::vector<treeNode*> & nodesTraversed){

    if (root == NULL){
        return false;
    }

    nodesTraversed.push_back(root);

    if(root->key == value){
        return true;
    }else if(root->key > value){
        return isPresent(root->leftNode, value, nodesTraversed);

    } else {
        return isPresent(root->rightNode, value, nodesTraversed);
    }
}

//funktionsaufruf in der main() (wusste nicht genau wohin damit)
std::vector<treeNode*> nodesTraversed;
bool nodeFound = isPresent(root, value, nodesTraversed);


//print vector

void NodeSearch::printSimpleSearch(int &value, std::vector<treeNode*> &nodesTraversed){
    if(NodeSearch == true){
    std::cout << value << " found " << std::endl;

    for(auto treeNode : nodesTraversed) {

        std::cout <<treeNode->key << ", " << std::endl;

    }
    }
    else {
        std::cout << value << "not found!" << std::endl;
    }

}


void NodeSearch::subTree(treeNode* root, std::vector<treeNode*> & subtreeNode);{

    if(root == NULL) {
        return std::cout<<"No AVL Tree present" << std::endl;
    }

    subtreeNode.push_back(root);
    subTree(root->leftNode, subtreeNode);
    subTree(root->rightNode, subtreeNode);


}

void NodeSearch::std::vector<treeNode*> findSubtree(treeNode* root, treeNode* subtreeRoot){

    std::vector<treeNode*> subtreeNode;
    subTree(subtreeRoot, subtreeNode);
    return subtreeNode;

}



bool NodeSearch::findSubtree(treeNode* root, treeNode* subtreeRoot, std::vector<treeNode*> &subtreeNode){

    if(root == NULL || subtreeRoot == NULL){
        return false;

    }

    if(root == subtreeRoot){

        subTree(subtreeRoot, subtreeNode);
        return true;

    }

    bool foundLeft = findSubtree(root->leftNode, subtreeRoot, subtreeNode);
    if(foundLeft){
        return true;
    }

     bool foundRight = findSubtree(root->rightNode, subtreeRoot, subtreeNode);
    if(foundright){
        return true;
    }

    return false;

}

void NodeSearch::printSubtree(){

    bool subtreefound = findSubtree(root, subtreeRoot, subtreeNode);

    if (subtreefound){
        std::cout << "Subtree found" << std::endl;
    }

   else {
    std::cout << "Subtree not found" << std::endl;
   }



}

