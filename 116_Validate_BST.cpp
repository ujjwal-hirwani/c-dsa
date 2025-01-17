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
bool validHelper(Node *root, Node *min, Node *max)
{
    if (root == NULL) return true;
    if (min != NULL && root->data < min->data)
        return false;
    if (max != NULL && root->data > max->data)
        return false;
    return validHelper(root->left, min, root) && validHelper(root->right, root, max);
}
bool validBST(Node *root)
{
    return validHelper(root, NULL, NULL);
}
int main()
{
    vector<int> nodes = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(nodes);
    root->left->data = 16; // BST invalidation.
    cout << validBST(root) << endl;
    return 0;
}