#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
int jump(const vector<vector<int>>& board, vector<vector<int>>& cache, int p, int q)
{
    int n = board.size();
    // base case
    if (p>=n || q>=n)
        return 0;
    if (p==n-1 && q==n-1)
        return 1;

    // memoization
    int& ret = cache[p][q];
    if (ret != -1)
        return ret;
    int value = board[p][q];
    ret = jump(board, cache, p+value, q) || jump(board, cache, p, q+value);
    return ret;
}
int main(void)
{
    int n_test;
    int n;
    cin >> n_test;
    while(n_test--)
    {
        cin >> n;
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> cache(n, vector<int>(n,-1));

        for (vector<int>& i : board)
            for (int& j : i)
                cin >> j;
        int result = jump(board, cache, 0, 0);
        if (result)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }

    return 0;
}