// USP
#include <iostream>
#include <vector>
#include <algorithm>
#include "ujjwal.h"
using namespace std;

int main()
{
    vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    Node *root = BuildTree(nodes);
    levelOrder(root);
    return 0;
}