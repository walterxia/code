#include "binarytree.h"

BtNode* BTree::createNewNode()
{
    BtNode* node = new BtNode();
    cout << "Crt addr:" << node << endl;
    node->lChild = node->rChild = nullptr;
    return node;
}

void BTree::destroyTree(BtNode* root) //@use post order for simplicity, otherwise, save child pointer before free node
{
    if(root)
    {
        if(root->lChild)
            destroyTree(root->lChild);
        if(root->rChild)
            destroyTree(root->rChild);
        cout << "Del addr:" << root << " val:" << root->value << endl;
        free(root);
    }
}

BTree::BTree()
    : _root(nullptr) {}

BTree::~BTree()
{
    destroyTree(_root);
}

BTree::BTree(const vector<char>& levelDatas)
{
    int eleNum = levelDatas.size();
    vector<BtNode*> nodeArray(eleNum, nullptr);
    for(auto i = 1; i < eleNum; ++i) //@ skip zero entry
    {
        const char &c = levelDatas[i];
        if( c != '#')
        {
            nodeArray[i] = createNewNode();
            nodeArray[i]->value = c;
        }
    }
    for(int j = 1; j <= eleNum / 2; ++j)
    {
        auto lPos = 2*j;
        if( lPos < eleNum && nodeArray[lPos]) //@ don't lose such 'lPos < eleNum'
            nodeArray[j]->lChild = nodeArray[lPos];
        auto rPos = 2*j + 1;
        if(rPos < eleNum && nodeArray[rPos])
            nodeArray[j]->rChild = nodeArray[rPos];
    }
    _root = nodeArray[1];
}

void BTree::preOrderTraversal(BtNode* root) const
{
    if(root)
    {
        cout << root->value << " ";
        if(root->lChild)   //@easy to forget this determine statement
            preOrderTraversal(root->lChild);
        if(root->rChild)
            preOrderTraversal(root->rChild);
    }
}

void BTree::inOrderTraversal(BtNode* root) const
{
    if(root)
    {
        if(root->lChild)
            inOrderTraversal(root->lChild);
        cout << root->value << " ";
        if(root->rChild)
            inOrderTraversal(root->rChild);
    }
}

void BTree::postOrderTraversal(BtNode* root) const
{
    if(root)
    {
        if(root->lChild)
            postOrderTraversal(root->lChild);
        if(root->rChild)
            postOrderTraversal(root->rChild);
        cout << root->value << " ";
    }
}

void BTree::preOrderTraversalNoRecur(BtNode* root) const
{
    
}

void BTree::dump(const TraversalType traversalType)
{
    cout << "BTree Dump using " << GetTraversalTypeStr(traversalType) << endl;
    if(!isEmpty())
    {
        if(traversalType == TraversalPreOrder)
            preOrderTraversal(_root);
        else if(traversalType == TraversalInOrder)
            inOrderTraversal(_root);
        else if(traversalType == TraversalPostOrder)
            postOrderTraversal(_root);
        cout << endl;
    }
    else
    {
        cout << "This is an empty binary tree!" << endl;
    }
}