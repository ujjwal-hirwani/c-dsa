// USP
#include <iostream>
#include <vector>
#include <queue>
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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;
    
    if (root1->data != root2->data)
        return false;
    
    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node *root, Node * subroot)
{
    // search for the root node
    if (root == NULL && subroot == NULL)
        return true;
    else if (root == NULL || subroot == NULL)
        return false;
    if (root->data == subroot->data)
    {
        // search for same structure.
        if (isIdentical(root, subroot))
            return true;
    }
    bool isInLeftSubtree = isSubtree(root->left, subroot);
    if (!isInLeftSubtree)
        return isSubtree(root->right, subroot);
    return true;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; 
    vector<int> subnodes = {2, 4, -1, -1, 5, -1, -1};
    Node *root = makeTree(nodes);
    idx = -1;
    Node *subroot = makeTree(subnodes);
    cout << boolalpha << isSubtree(root, subroot) << endl; 
    return 0;
}