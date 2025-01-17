// USP
#include <iostream>
#include <vector>
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
        left = right = NULL;
    }
};
Node* insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}
Node* buildBST(vector<int> nodes)
{
    Node *root = NULL;
    for (int i = 0; i < nodes.size(); i++)
    {
        root = insert(root, nodes[i]);
    }
    return root;
}

void printInRange(Node *root, int start, int end)
{
    if (root == NULL)
        return;
    // in range;
    if (root->data >= start && root->data <= end)
    {
        printInRange(root->left, start, end); // do it like inorder traversal to print it in sorted manner.
        cout << root->data << "\t";
        printInRange(root->right, start, end);
    }
    else if (root->data < start)
        printInRange(root->right, start, end);
    else
        printInRange(root->left, start, end);
}
int main()
{
    vector<int> nodes = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(nodes);
    printInRange(root, 5, 12);
    return 0;
}