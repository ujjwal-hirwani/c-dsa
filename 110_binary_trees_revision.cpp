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
        left = NULL;
        right = NULL;
    }
};
static int idx = -1;
Node *BuildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
        return NULL;
    Node *currNode = new Node(nodes[idx]);
    currNode->left = BuildTree(nodes);
    currNode->right = BuildTree(nodes);

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
            cout << curr->data << "\t";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int sumNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
pair<int, int> diameter(Node *root) // diameter, height
{
    if (root == NULL)
        return make_pair(0, 0);
    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    int currDia = left.second + right.second + 1;
    int leftDia = left.first;
    int rightDia = right.first;

    int leftHeight = left.second;
    int rightHeight = right.second;

    int dia = max(currDia, max(leftDia, rightDia));
    int height = max(leftHeight, rightHeight) + 1;

    return make_pair(dia, height);
}
void topView(Node *root)
{
    if (root == NULL)
        return;
    map<int, Node*> m; // hd, Node*
    // using level order traversal.
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node*, int> curr = q.front();
        q.pop();
        if (m.count(curr.second) != 1)
            m[curr.second] = curr.first;
        
        if (curr.first->left != NULL)
            q.push(make_pair(curr.first->left, curr.second - 1));
        
        if (curr.first->right != NULL)
            q.push(make_pair(curr.first->right, curr.second + 1));
    }
    for (auto it : m)
    {
        cout << it.second->data << "\t";
    }
    cout << endl;
}
void bottomView(Node *root)
{
    if (root == NULL)
        return;
    map<int, Node*> m; // hd, Node*
    // using level order traversal.
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node*, int> curr = q.front();
        q.pop();
            m[curr.second] = curr.first;
        
        if (curr.first->left != NULL)
            q.push(make_pair(curr.first->left, curr.second - 1));
        
        if (curr.first->right != NULL)
            q.push(make_pair(curr.first->right, curr.second + 1));
    }
    for (auto it : m)
    {
        cout << it.second->data << "\t";
    }
    cout << endl;
}
int main()
{
    vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    Node *root = BuildTree(nodes);
    // levelOrder(root);
    // cout << height(root) << endl;
    // cout << countNodes(root) << endl;
    // cout << sumNodes(root) << endl;
    // cout << diameter(root).first << endl;
    topView(root);
    bottomView(root);
    return 0;
}