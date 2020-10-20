#include <iostream>
#include <vector>
#include <array>
using namespace std;

struct BtNode
{
    char value;
    BtNode *lChild;
    BtNode *rChild;
};

enum TraversalType
{
    TraversalPreOrder,
    TraversalInOrder,
    TraversalPostOrder
};

#define GetTraversalTypeStr(type) (type == TraversalPreOrder ? "PreOrder" : \
                                   type == TraversalInOrder ? "InOrder" : \
                                   type == TraversalPostOrder ? "PostOrder" : \
                                   "Error")

class BTree
{
    public:
        BTree();
        ~BTree();
        BTree(const vector<char>& levelDatas); // level traversal input. '#' means empty. considered as Complete

        bool isEmpty() const{ return _root == nullptr;}

        void preOrderTraversal(BtNode* root) const; // recursive style    sequence: root, left tree, right tree
        void inOrderTraversal(BtNode* root) const; // recursive style    sequence: left tree, root, right tree
        void postOrderTraversal(BtNode* root) const; // recursive style    sequence: left tree, right tree, root

        void preOrderTraversalNoRecur(BtNode* root) const; // recursive style    sequence: root, left tree, right tree


        void dump(const TraversalType traversalType = TraversalPreOrder);

    private:
        BtNode* createNewNode();
        void destroyTree(BtNode* root);

        BtNode* _root;
};