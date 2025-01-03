// USP
// leetcode 2129 must do.!!!
# include <iostream>
# include <queue>
using namespace std;
void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}
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