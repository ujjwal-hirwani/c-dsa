// USP
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    }
};

int idx = -1;
Node *makeTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
        return NULL;

    Node *curr = new Node(nodes[idx]);
    curr->left = makeTree(nodes);
    curr->right = makeTree(nodes);
    return curr;
}

void traverse(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << endl;
    traverse(root->left);
    traverse(root->right);
}

void KthHelper(Node *root, int currLevel, int k)
{
    if (root == NULL)
        return;
    if (currLevel == k)
    {
        cout << root->data << " ";
        return;
    }
    KthHelper(root->left, currLevel + 1, k);
    KthHelper(root->right, currLevel + 1, k);
}
void KthLevel(Node *root, int k)
{
    KthHelper(root, 1, k);
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = makeTree(nodes);
    KthLevel(root, 2);
    return 0;
}