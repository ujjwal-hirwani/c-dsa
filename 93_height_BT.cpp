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
int height(Node *root)
{

    if (root == NULL)
        return 0;

    // int leftHt = height(root->left);
    // int rightHt = height(root->right);
    // int currHt = max(leftHt, rightHt) + 1;

    // return currHt; 
    return max(height(root->left), height(root->right)) + 1;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node *root = makeTree(nodes);
    cout << height(root) << endl;
    return 0;
}