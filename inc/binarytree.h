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
    TraversalPostOrder,
    TraversalLevelOrder
};

enum InvokeType
{
    InvokeRecursive,
    InvokeNoRecursive
};

#define GetTraversalTypeStr(type) (type == TraversalPreOrder ? "PreOrder" : \
                                   type == TraversalInOrder ? "InOrder" : \
                                   type == TraversalPostOrder ? "PostOrder" : \
                                   type == TraversalLevelOrder ? "LevelOrder" : \
                                   "Error")

#define GetInvokeTypeStr(type) (type == InvokeRecursive ? "Recursive" : \
                                   type == InvokeNoRecursive ? "NoRecursive" : \
                                   "Error")

class BTree
{
    public:
        BTree();
        ~BTree();
        BTree(const vector<char>& levelDatas); // level traversal input. '#' means empty. considered as Complete

        bool isEmpty() const{ return _root == nullptr;}

        void preOrder(BtNode* root) const; // recursive style    sequence: root, left tree, right tree
        void inOrder(BtNode* root) const; // recursive style    sequence: left tree, root, right tree
        void postOrder(BtNode* root) const; // recursive style    sequence: left tree, right tree, root

        void preOrderNoRecur(BtNode* root) const; // No recursive style
        void inOrderNoRecur(BtNode* root) const; // No recursive style
        void postOrderNoRecur(BtNode* root) const; // No recursive style

        void dump(const TraversalType traversalType = TraversalPreOrder, const InvokeType invokeType = InvokeRecursive);

    private:
        BtNode* createNewNode();
        void destroyTree(BtNode* root);

        BtNode* _root;
};