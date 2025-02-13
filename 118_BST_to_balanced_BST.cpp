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
void getInorder(Node *root, vector<int>& path)
{
    if (root == NULL)
        return;
    getInorder(root->left, path);
    path.push_back(root->data);
    getInorder(root->right, path);
}
Node* buildBSTfromSortedArray(vector<int> arr, int low, int high)
{
    if (low > high)
        return NULL;
    int mid = low + (high - low) / 2;
    Node *curr = new Node(arr[mid]);
    curr->left = buildBSTfromSortedArray(arr, low, mid - 1);
    curr->right = buildBSTfromSortedArray(arr, mid + 1, high);
    return curr;
}
Node* BalanceBST(Node *root)
{
    vector<int> path;
    getInorder(root, path);
    Node *curr = buildBSTfromSortedArray(path, 0, path.size() - 1);
    return curr;
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<int> nodes = {6, 5, 4, 3, 7, 8, 9};
    Node *root = buildBST(nodes);
    preorder(root); cout << endl;
    root = BalanceBST(root);
    preorder(root); cout << endl;
    return 0;
}