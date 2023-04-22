#ifndef NODESEARCH_H
#define NODESEARCH_H


class NodeSearch
{
    public:
        NodeSearch();
        virtual ~NodeSearch();
        bool isPresent(Pointer für den Baum (treeNode* root), int value, vector<treeNode*> & nodesTraversed);
        void printSimpleSearch(int &value, std::vector<treeNode*> &nodesTraversed)
        void subTreeNode(treeNode* root, std::vector<treeNode*> & subtreeNode);
        void std::vector<treeNode*> findSubtree(treeNode* root, treeNode* subtreeRoot);
        bool findSubtree(treeNode* root, treeNode* subtreeRoot, std::vector<treeNode*> &subtreeNode);
        void printSubtree();

    protected:

    private:
};

#endif // NODESEARCH_H
