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

void traverse(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << endl;
    traverse(root->left);
    traverse(root->right);
}

int distance(Node *root, int n, int i)
{
    if (root == NULL)
        return -1;
    if (root->data == n)
        return i;
    int left = distance(root->left, n, i + 1);
    int right = distance(root->right, n, i + 1);

    return left == -1 ? right : left;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = makeTree(nodes);
    cout << distance(root, 6, 0) << endl;
    return 0;
}