// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int idx = -1;
Node *makeTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
        return NULL;
    Node *currNode = new Node(nodes[idx]);

    currNode->left = makeTree(nodes);
    currNode->right = makeTree(nodes);

    return currNode;
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node *root = makeTree(nodes);
    cout << countNodes(root) << endl;
    return 0;
}