struct BtNode
{
    int value;
    BtNode *leftChild;
    BtNode *rightChild;
};

class BTree
{
    public:
        BTree(){}

        void dump(){std::cout << "BTree Dump" << std::endl;}

    private:
        BtNode* root;
};