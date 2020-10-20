#include <unordered_set>

#include "binarytree.h"

int main(int argc, char** argv)
{
    int j= 88, i;
    unordered_set<int> set{78, 89, 33};
    cout << "hello wolrd powered by VS CODE" << endl;
    cout << set.bucket_count() << endl;

    BTree bt;
    bt.dump();
    
    return 0;
}