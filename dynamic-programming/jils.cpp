#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int jils(const vector<int>& A, const vector<int>& B, vector<vector<int>>& cache, int a, int b);
void printCache(vector<vector<int>>& cache);

int main(void)
{
    int n_test;
    cin >> n_test;
    int n, m;
    while (n_test--)
    {
        cin >> n >> m;
        vector<int> A(n, -1);
        vector<int> B(m, -1);
        for (int i=0; i<n; i++)
            cin >> A[i];
        for (int i=0; i<m; i++)
            cin >> B[i];
        vector<vector<int>> cache(n, vector<int>(m, -1));
        // cache[n-1][m-1] = (A[n-1] != B[m-1]) ? 2 : 1;
        jils(A,B,cache,0,0);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                // if (cache[i][j] == -1)
                jils(A,B,cache, i, j);
            }
        int result = 0;

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                if (result < cache[i][j])
                    result = cache[i][j];
            }
        printCache(cache);
        cout << result << endl;
    }
}
void printCache(vector<vector<int>>& cache)
{
    int a = cache.size();
    int b = cache[0].size();
    for (vector<int> i : cache)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
}
int jils(const vector<int>& A, const vector<int>& B, vector<vector<int>>& cache, int a, int b)
{
    // printCache(cache);
    int& ret = cache[a][b];
    if (ret != -1)
    {
        return ret;
    }
    int valueA = A[a];
    int valueB = B[b];
    int max_ele = max(valueA, valueB);
    int longestA = (valueA != valueB) ? 2 : 1;
    int k = 0;
    for (int i=a+1; i<A.size(); i++)
    {
        if (A[i] > max_ele)
        {
            k=1;
            int temp = jils(A,B,cache, i, b);
            if (longestA < temp)
            {
                longestA = temp;
            }
        }
    }
    int longestB = (valueA != valueB) ? 2 : 1;
    for (int i=b+1; i<B.size(); i++)
    {
        if (B[i] > max_ele)
        {
            k=1;
            int temp = jils(A,B,cache, a, i);
            if (longestB < temp)
            {
                longestB = temp;
            }
        }
    }
    // int k = (valueA != valueB) ? 1 : 0;
    ret = (longestA > longestB) ? longestA+k : longestB+k;
    return ret;
}