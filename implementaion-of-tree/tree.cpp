#include <iostream>
#include <vector>

using namespace std;
class Tree;

class TreeNode
{
private:
    friend class Tree;
    char data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr)
    {
        this->data = data;
        this->left = left; 
        this->right = right;
    }
};

class Tree
{
private:
    TreeNode* root;

public:
    void deleteNode(TreeNode* current)
    {
        if (current == nullptr)
            return;
        deleteNode(current->left);
        deleteNode(current->right);
        delete current;
    }

    Tree(char data)
    {
        root = new TreeNode(data);
    }
    ~Tree()
    {
        deleteNode(root);
    }
    
    TreeNode* getRoot()
    {
        return root;
    }

    TreeNode* searchNode(TreeNode* current, char data)
    {
        if (current == nullptr)
            return nullptr;
        if (current->data == data)
            return current;
        TreeNode* left = searchNode(current->left, data);
        if (left != nullptr)
            return left;
        TreeNode* right = searchNode(current->right, data);
        if (right != nullptr)
            return right;
        return nullptr;
    }

    void insertNode(TreeNode* parentNode, char data, bool isleft)
    {
        TreeNode* newNode = new TreeNode(data);
        if (isleft)
            parentNode->left = newNode;
        else
        {
            parentNode->right = newNode;
        }
    }

    void printPreorder(TreeNode* current)
    {
        if (current == nullptr)
            return;
        cout << current->data;
        printPreorder(current->left);
        printPreorder(current->right);
    }

    void printInorder(TreeNode* current)
    {
        if (current == nullptr)
            return;
        printInorder(current->left);
        cout << current->data;
        printInorder(current->right);
    }

    void printPostorder(TreeNode* current)
    {
        if (current == nullptr)
            return;
        printPostorder(current->left);
        printPostorder(current->right);
        cout << current->data;
    }
};

int main(void)
{
    int n_node;
    cin >> n_node;

    char a,b,c;
    cin >> a >> b >> c;
    Tree tree = Tree(a);
    TreeNode* root = tree.getRoot();
    if (b != '.')
        tree.insertNode(root, b, true);
    if (c != '.')
        tree.insertNode(root, c, false);

    for (int i=0; i<n_node-1; i++)
    {
        cin >> a >> b >> c;
        TreeNode* parent = tree.searchNode(root, a);
        if (b != '.')
            tree.insertNode(parent, b, true);
        if (c != '.')
            tree.insertNode(parent, c, false);
    }

    tree.printPreorder(root);
    cout << endl;
    tree.printInorder(root);
    cout << endl;
    tree.printPostorder(root);
    return 0;
}