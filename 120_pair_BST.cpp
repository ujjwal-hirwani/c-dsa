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
        left = right = NULL;
    }
};
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
Node *buildBST(vector<int> nodes)
{
    Node *root = NULL;
    for (int i = 0; i < nodes.size(); i++)
    {
        root = insert(root, nodes[i]);
    }
    return root;
}
void getInorder(Node *root, vector<int> &path)
{
    if (root == NULL)
        return;
    getInorder(root->left, path);
    path.push_back(root->data);
    getInorder(root->right, path);
}
bool checkPair(Node *root1, Node *root2, int target)
{
    vector<int> path1;
    vector<int> path2;
    getInorder(root1, path1);
    getInorder(root2, path2);
    int low = 0, high = path2.size() - 1;
    while (low < path1.size() && high >= 0)
    {
        if (path1[low] + path2[high] == target)
            return true;
        if (path1[low] + path2[high] < target)
            low++;
        else
            high--;
    }
    return false;
}
int main()
{
    vector<int> nodes1 = {5, 3, 2, 4, 7, 6, 8};
    Node *root1 = buildBST(nodes1);
    vector<int> nodes2 = {10, 6, 3, 8, 15, 11, 18};
    Node *root2 = buildBST(nodes2);
    cout << checkPair(root1, root2, 0) << endl;
    return 0;
}