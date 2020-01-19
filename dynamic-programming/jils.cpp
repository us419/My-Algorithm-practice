#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int jils(const vector<int>& A, const vector<int>& B, vector<vector<int>>& cache, int a, int b);
void printCache(vector<vector<int>>& cache);
int smallest = numeric_limits<int>::min();

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
        vector<vector<int>> cache(n+1, vector<int>(m+1, -1));
        int result = jils(A,B,cache, -1, -1);
        // printCache(cache);
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
    int& ret = cache[a+1][b+1];
    if (ret != -1)
    {
        return ret;
    }
    long long valueA = (a == -1) ? smallest : A[a];
    long long valueB = (b == -1) ? smallest : B[b];
    int max_ele = max(valueA, valueB);
    int longest = 0;
    for (int i=a+1; i<A.size(); i++)
    {
        if (A[i] > max_ele)
        {
            longest = max(longest, jils(A,B,cache, i,b)+1);
        }
    }
    for (int i=b+1; i<B.size(); i++)
    {
        if (B[i] > max_ele)
        {
            longest = max(longest, jils(A,B,cache,a,i)+1);
        }
    }
    ret = longest;
    return ret;
}