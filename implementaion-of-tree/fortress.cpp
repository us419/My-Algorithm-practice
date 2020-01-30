#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
int longest = 0;

int sqt(int x)
{
    return x*x;
}

class Node
{
    friend class Tree;
private:
    int x;
    int y;
    int r;
    list<Node*> childs;
public:
    Node(int x, int y, int r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
};

class Tree
{
private:
    Node* root;
public:
    void deleteNode(Node* current)
    {
        if (current->childs.empty())
        {
            delete current;
            return;
        }
        for (Node* child : current->childs)
            deleteNode(child);
        delete current;
    }

    Tree(int x, int y, int r)
    {
        root = new Node(x,y,r);
    }

    ~Tree()
    {
        deleteNode(root);
    }

    Node* getRoot()
    {
        return root;
    }

    int isParent(Node* parent, Node* child)
    {
        int distance = sqt(parent->x - child->x) + sqt(parent->y - child->y);
        if (distance < sqt(parent->r) && parent->r > child->r)
            return 1;   // parent가 큼
        if (distance < sqt(child->r) && parent->r < child->r)
            return 2;   // child가 큼
        return 0;   // 둘이 brother
    }
    void insertNode(Node* current, Node* newNode)
    {
        int isBrother = 1;
        vector<Node*> remove_list;
        for (Node* child : current->childs)
        {
            if (isParent(newNode, child) == 1)
            {
                remove_list.push_back(child);
                isBrother = 0;
            }
            else if (isParent(newNode, child) == 2)
            {
                isBrother = 0;
                insertNode(child, newNode);
                break;
            }
        }
        if (!remove_list.empty())
        {
            current->childs.push_back(newNode);
            for (Node* child : remove_list)
            {
                newNode->childs.push_back(child);
                current->childs.remove(child);
            }
        }
        if (isBrother == 1)
        {
            current->childs.push_back(newNode);
        }
    }

    int height(Node* current)
    {
        vector<int> heights;
        if (current->childs.empty())
            return 0;
        for (Node* child : current->childs)
        {  
            heights.push_back(height(child));
        }
        sort(heights.begin(), heights.end());
        if (heights.size() >= 2)
            longest = max(longest, 2 + heights[heights.size()-2] + heights[heights.size()-1]);
        return heights.back()+1;
    }
};


int main(void)
{
    longest = 0;
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n;
        cin >> n;
        int x,y,r;
        cin >> x >> y >> r;
        Tree tree = Tree(x,y,r);
        Node* root = tree.getRoot();
        for (int i=0; i<n-1; i++)
        {
            cin >> x >> y >> r;
            Node* newNode = new Node(x,y,r);
            tree.insertNode(root, newNode);
        }
        int tree_height = tree.height(root);
        cout << max(tree_height, longest) << endl;
    }
    return 0;
}