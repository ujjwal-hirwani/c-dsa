// USP
#include <iostream>
#include <vector>
#include <queue>
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
    root->data = 0;
}

int sumNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int treeToSumTree(Node *root)\
// returns the current value of nodes.
{
    if (root == NULL)
        return 0;
    int left = treeToSumTree(root->left); // old value of the left node
    int right = treeToSumTree(root->right); // old value of the right node
    int currData = root->data;
    int leftData = root->left == NULL ? 0 : root->left->data;
    int rightData = root->right == NULL ? 0 : root->right->data;
    root->data = leftData + rightData + left + right; // Sum = value of left + value of right    
    return currData;                                       // old value of left + old value of right
}
void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            if (q.empty())
                break;
            q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}
int main()
{
    vector<int> nodes = {-10, 9, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    Node *root = makeTree(nodes);
    treeToSumTree(root);
    levelOrder(root);
    return 0;
}