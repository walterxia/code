#include <unordered_set>
#include "binarytree.h"
#include "lt.h"

void algo()
{
    BTree bt0;
    bt0.dump();
    cout << "--------------------------------------------------" << endl;
    array<char, 13> levelDatasArray = {'#', 'C', 'D', 'A', '#', 'E', 'B', 'G', '#', '#', '#', '#', 'H'};
    vector<char> levelDatas(levelDatasArray.cbegin(), levelDatasArray.cend());
    BTree bt(levelDatas);
    bt.dump();
    bt.dump(TraversalPreOrder, InvokeNoRecursive);

    bt.dump(TraversalInOrder);
    bt.dump(TraversalInOrder, InvokeNoRecursive);

    bt.dump(TraversalPostOrder);
    bt.dump(TraversalPostOrder, InvokeNoRecursive);

    bt.dump(TraversalLevelOrder);
}

int main(int argc, char** argv)
{
    //algo();

    ltMain();
    
    return 0;
}