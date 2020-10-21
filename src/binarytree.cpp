#include "binarytree.h"

#include <stack>

BtNode* BTree::createNewNode()
{
    BtNode* node = new BtNode();
    //cout << "Crt addr:" << node << endl;
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
        //cout << "Del addr:" << root << " val:" << root->value << endl;
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

void BTree::preOrder(BtNode* root) const
{
    if(root)  // recursive end condition
    {
        cout << root->value << " ";
        if(root->lChild)   //@also ok if there is no such check
            preOrder(root->lChild);
        if(root->rChild)
            preOrder(root->rChild);
    }
}

void BTree::inOrder(BtNode* root) const
{
    if(root)
    {
        if(root->lChild)
            inOrder(root->lChild);
        cout << root->value << " ";
        if(root->rChild)
            inOrder(root->rChild);
    }
}

void BTree::postOrder(BtNode* root) const
{
    if(root)
    {
        if(root->lChild)
            postOrder(root->lChild);
        if(root->rChild)
            postOrder(root->rChild);
        cout << root->value << " ";
    }
}

void BTree::preOrderNoRecur(BtNode* root) const
{
    if(root)
    {
        stack<BtNode*> treeStack;
        auto curr = root;
        while(curr)// || !treeStack.empty())  //@skip check stack if empty here
        {
            cout << curr->value << " " ;
            treeStack.push(curr);
            curr = curr->lChild;

            while(!curr && !treeStack.empty())
            {
                curr = treeStack.top();
                treeStack.pop();
                curr = curr->rChild;
            }
        }
    }
}

void BTree::inOrderNoRecur(BtNode* root) const
{
    if(root)
    {
        stack<BtNode*> treeStack;
        auto curr = root;
        while(curr)
        {
            treeStack.push(curr);
            curr = curr->lChild;

            while(!curr && !treeStack.empty())
            {
                curr = treeStack.top();
                treeStack.pop();
                cout << curr->value << " " ;
                curr = curr->rChild;
            }
        }
    }
}

void BTree::postOrderNoRecur(BtNode* root) const
{
    if(root)
    {
        stack<BtNode*> treeStack;
        auto curr = root;
        while(curr)
        {
            treeStack.push(curr);
            curr = curr->lChild;

            while(!curr && !treeStack.empty())
            {
                curr = treeStack.top();
                treeStack.pop();
                cout << curr->value << " " ;
                curr = curr->rChild;
            }
        }
    }
}

void BTree::dump(const TraversalType traversalType, const InvokeType invokeType)
{
    cout << "BTree Dump using " << GetTraversalTypeStr(traversalType) << "" << GetInvokeTypeStr(invokeType) << endl;
    if(!isEmpty())
    {
        if(traversalType == TraversalPreOrder)
        {
            if(invokeType == InvokeRecursive)
                preOrder(_root);
            else
                preOrderNoRecur(_root);
        }
        else if(traversalType == TraversalInOrder)
        {
            if(invokeType == InvokeRecursive)
                inOrder(_root);
            else
                inOrderNoRecur(_root);
        }
        else if(traversalType == TraversalPostOrder)
        {
            if(invokeType == InvokeRecursive)
                postOrder(_root);
            else
                postOrderNoRecur(_root);
        }
        else if(traversalType == TraversalLevelOrder)
            cout << "TBD" << endl;
        cout << endl;
    }
    else
    {
        cout << "This is an empty binary tree!" << endl;
    }
}