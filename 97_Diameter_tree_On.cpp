// USP
#include <iostream>
#include <vector>
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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
pair<int, int> diameter(Node *root) // O(n^2)
{
    if (root == NULL)
        return make_pair(0, 0); // (diameter, height)
    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);
    int currDia = left.second + right.second + 1;
    int currHeight = max(left.second, right.second) + 1;
    int finalDia = max(currDia, max(left.first, right.first));

    return make_pair(finalDia, currHeight);
}
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
int main()
{
    vector<int> nodes = {1, 2, 4, 9, 10, -1, -1, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node *root = makeTree(nodes);
    cout << diameter(root).first << endl;
    return 0;
}