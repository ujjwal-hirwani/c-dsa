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
void traverse(Node *root)
{
    if (root == NULL)
        return;
    traverse(root->left);
    cout << root->data << endl;
    traverse(root->right);
}
int main()
{
    vector<int> nodes = {5, 1, 3, 4, 2, 7};
    Node *root = buildBST(nodes);
    traverse(root);
    return 0;
}