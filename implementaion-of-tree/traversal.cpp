#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPostorder(const vector<int>& preorder, const vector<int>& inorder);
vector<int> slice(const vector<int>& v, int a, int b);

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        int n;
        cin >> n;
        vector<int> preorder(n,0);
        vector<int> inorder(n,0);
        for (int i=0; i<n; i++)
            cin >> preorder[i];
        for (int i=0; i<n; i++)
            cin >> inorder[i];
        printPostorder(preorder, inorder);        
    }
    return 0;
}
vector<int> slice(const vector<int>& v, int a, int b)
{
    return vector<int>(v.begin()+a, v.begin()+b);
}

void printPostorder(const vector<int>& preorder, const vector<int>& inorder)
{
    int N = inorder.size();
    if (N == 0)
        return;
    int root = preorder[0];
    int left_length = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    printPostorder(slice(preorder, 1, left_length+1), slice(inorder, 0, left_length));
    printPostorder(slice(preorder, 1+left_length, N), slice(inorder, 1+left_length, N));
    cout << root << " ";
}