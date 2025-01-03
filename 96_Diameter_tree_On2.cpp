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
int height(Node *root)
{
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(Node *root) // O(n^2)
{
    if (root == NULL)
        return 0;
    // assuming diameter passes through root.
    int currDia = height(root->left) + height(root->right) + 1; // O(n)
    // assuming diameter does not passes through root.
    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);

    return max(currDia, max(leftDia, rightDia)); 
}
int idx = -1;
Node* makeTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
        return NULL;
    Node *curr = new Node(nodes[idx]);
    curr->left = makeTree(nodes);
    curr->right = makeTree(nodes);

    return curr;
}
int main()
{
    vector<int> nodes = {1, 2, 4, 9, 10, -1, -1, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node *root = makeTree(nodes);
    cout << diameter(root) << endl;
    return 0;
}