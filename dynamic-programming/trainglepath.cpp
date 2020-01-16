#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_path(const vector<vector<int>>& board, vector<vector<int>>& cache, int p, int q);

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n;
        cin >> n;
        vector<vector<int>> board(n, vector<int>(n,0));
        for (int i=0;i<n;i++)
            for (int j=0;j<=i;j++)
            {
                cin >> board[i][j];
            }
        vector<vector<int>> cache(n, vector<int>(n,-1));
        cache[0][0] = board[0][0];
        int length = 0;
        int temp;
        for (int i=0;i<n;i++)
        {
            temp = longest_path(board, cache, n-1, i);
            if (length < temp)
                length = temp;
        }
        cout << length << endl;
    }
}

int longest_path(const vector<vector<int>>& board, vector<vector<int>>& cache, int p, int q)
{
    int& ret = cache[p][q];
    if (ret != -1)
        return ret;
    
    if (p < q)
        return ret;

    if (q == 0)
    {
        ret = board[p][q] + longest_path(board, cache, p-1, q);
        return ret;
    }

    else
    {
        ret = board[p][q] + max(longest_path(board, cache, p-1, q), longest_path(board, cache, p-1, q-1));
        return ret;
    }
}