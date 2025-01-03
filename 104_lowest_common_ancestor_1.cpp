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

bool findPath(Node *root, int n, vector<int> &path) // code to find path from root to a node.
{
    if (root == NULL)
        return false;
    path.push_back(root->data); // Assuming that the current node belonga to the path.
    if (root->data == n) // if the current node-> data == n, ie. current node is the node we are searching for.
                        // return true.
        return true;
    
    bool isLeft = findPath(root->left, n, path); // If not search in left and right subtree.
    bool isRight = findPath(root->right, n, path);

    if (isLeft || isRight) // if the node exists in either of the subtree, return true.
        return true;
    
    path.pop_back(); // else pop the current node as it does not belog to the path.
    return false; // return false.
}

int LCA(Node *root, int n1, int n2) // code to find LCA
{
    // logic: the last common element in the paths pf node n1 and n2 from the root is LCA 
    vector<int> path1, path2;
    findPath(root, n1, path1);
    findPath(root, n2, path2);

    int LCA = -1;

    for (int i = 0, j = 0; i < path1.size(), j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
            return LCA; // The last commob element in path1 and path2 is the LCA.
        LCA = path1[i];
    }
    return LCA;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = makeTree(nodes);

    cout << LCA(root, 5, 6) << endl;
    return 0;
}