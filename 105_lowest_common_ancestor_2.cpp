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

Node *LCA(Node *root, int n1, int n2) // code to find LCA
// logic: LCA is the node whose left and right subtree contains n1 or n2.
{
    if (root == NULL) 
        return NULL;

    if (root->data == n1 || root->data == n2) // if current node is equal to n1 or n2, return root.
        return root;

    Node *leftLCA = LCA(root->left, n1, n2); // check for left and right nodes.
    Node *rightLCA = LCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) // Node found: gets value from both left and right subtree.
        return root;
    
    return leftLCA == NULL ? rightLCA : leftLCA; // if leftLCA == NULL return rightLCA, else return leftLCA, else return NULL.
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = makeTree(nodes);
    return 0;
}