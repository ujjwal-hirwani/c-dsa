// USP
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void topView(Node *root)
{
    queue<pair<Node*, int>> q; // (Node, HD)  HD = horizontal distance
    map<int, int> m; // (HD, Node->data)

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node*, int> curr = q.front();
        q.pop();
        Node *currNode = curr.first;
        int currHD = curr.second;

        if (m.count(currHD) == 0)
            m[currHD] = currNode->data;
        
        if (currNode->left != NULL)
        {
            q.push(make_pair(currNode->left, currHD - 1));
        }
        if (currNode->right != NULL)
        {
            q.push(make_pair(currNode->right, currHD + 1));
        }
    }
    for (auto it : m)
    {
        cout << it.second << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; 
    Node *root = makeTree(nodes);
    traverse(root);
    topView(root);
    return 0;
}