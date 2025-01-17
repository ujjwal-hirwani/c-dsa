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
    cout << root->data << "\t";
    traverse(root->right);
}
Node* getInorderSuccessor(Node *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        // root = val;
        // case 1: 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 2: 1 child
        if (root->left == NULL || root->right == NULL)
        {
            Node *ret = root->left == NULL ? root->right : root->left;
            delete root;
            return ret;
        }
        // case 3: 2 children
        Node *IS = getInorderSuccessor(root);
        root->data = IS->data;
        root->right = deleteNode(root->right, root->data); // case 1, case 2
        return root;
    }
    // Note: return for case 3 is given by case 1 and case 2 respectively.
}
int main()
{
    vector<int> nodes = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(nodes);
    traverse(root);
    cout << endl;
    root = deleteNode(root, 5);
    traverse(root);
    cout << endl;
    return 0;
}