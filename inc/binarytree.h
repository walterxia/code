#include <iostream>
using namespace std;

struct BtNode
{
    int value;
    BtNode *leftChild;
    BtNode *rightChild;
};

class BTree
{
    public:
        BTree();

        void dump(){cout << "BTree Dump" << endl;}

    private:
        BtNode* root;
};