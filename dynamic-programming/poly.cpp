#include <iostream>
#include <vector>

using namespace std;
int poly(vector<vector<int>>& cache, int remained_n, int first_row);
void printCache(vector<vector<int>>& cache);

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cache(n, vector<int>(n, -1));
        int result = 0;
        for (int i=1; i<=n; i++)
        {
            result += poly(cache, n, i) % 10000000;
            result %= 10000000;
        }
        cout << result << endl;
    }
    return 0;
}

void printCache(vector<vector<int>>& cache)
{
    for (vector<int> i : cache)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
}

int poly(vector<vector<int>>& cache, int remained_n, int first_row)
{
    int& ret = cache[remained_n-1][first_row-1];
    if (ret != -1)
        return ret;
    
    if (first_row > remained_n)
        return ret = 0;
    if (first_row == remained_n)
        return ret = 1;

    ret = 0;
    for (int second=1; second<=remained_n-first_row; second++)
    {
        ret += ((first_row + second - 1) * poly(cache, remained_n-first_row, second)) % 10000000;
        ret %= 10000000;
    }
    return ret;
}