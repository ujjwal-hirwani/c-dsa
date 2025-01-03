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

int KthAcestor(Node *root, int node, int k) // O(n)
// the return type int here does not return the value of Kth ancestor, instead it returns
// the distance of the current node the from the given node.
// this actually returns the avlue of k at the end.
{
    if (root == NULL)
        return -1;
    if (root->data == node)
        return 0;
    int leftDist = KthAcestor(root->left, node, k);
    int rightDist = KthAcestor(root->right, node, k);

    if (leftDist == -1 && rightDist == -1)
        return -1;

    int validVal = leftDist == -1 ? rightDist : leftDist;

    if (validVal + 1 == k)
        cout << "Kth Ancestor: " << root->data << endl;
    return validVal + 1;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = makeTree(nodes);
    KthAcestor(root, 5, 1);
    return 0;
}