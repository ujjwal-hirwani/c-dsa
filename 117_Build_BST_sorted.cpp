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
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}

Node *buildBSTfromSortedArray(vector<int> arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    Node *curr = new Node(arr[mid]);
    curr->left = buildBSTfromSortedArray(arr, start, mid - 1);
    curr->right = buildBSTfromSortedArray(arr, mid + 1, end);
    return curr;
}

int main()
{
    vector<int> arr = {3, 4, 5, 6, 7, 8, 9};
    Node *root = buildBSTfromSortedArray(arr, 0, arr.size() - 1);
    inorder(root); cout << endl;
    preorder(root); cout << endl;
    return 0;
}