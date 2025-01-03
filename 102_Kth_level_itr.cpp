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

void KthLevel(Node *root, int k)
{
    int count = 1;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (q.empty())
                break;
            count++;
            q.push(NULL);
        }
        else
        {
            if (count > k)
                break;
            if (count == k)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    cout << endl;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = makeTree(nodes);
    KthLevel(root, 1);
    return 0;
}