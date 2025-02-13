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
void minDifference(Node *root, int k, int& diff, Node*& node)
{
    if (root == NULL)
        return;
    if (root->data == k)
    {
        diff = 0;
        return;
    }
    if (root->data > k)
    {
        int d = root->data > k? root->data - k : k - root->data;
        if (d < diff)
        {
            diff = d;
            node = root;
        }
        minDifference(root->left, k, diff, node);
    }
    else
    {
        int d = root->data > k? root->data - k : k - root->data;
        if (d < diff)
        {
            diff = d;
            node = root;
        }
        minDifference(root->right, k, diff, node);
    }
}
int main()
{
    vector<int> nodes = {8, 5, 3, 6, 11, 20};
    Node *root = buildBST(nodes);
    int target = 19, diff = INT32_MAX;
    Node *node;
    minDifference(root, target, diff, node);
    cout << diff << endl;
    cout << node->data << endl;
    return 0;
}