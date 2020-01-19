#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cal_path(const vector<vector<int>>& triangle, vector<vector<int>>& cache, int p, int q);
void printCache(const vector<vector<int>>& cache);
int num_path(const vector<vector<int>>& triangle, const vector<vector<int>>& cache, vector<vector<int>>& cache2, int p, int q);

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n;
        cin >> n;
        vector<vector<int>> triangle(n, vector<int>(n,0));
        vector<vector<int>> cache(n, vector<int>(n,-1));
        vector<vector<int>> cache2(n, vector<int>(n,-1));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<i+1; j++)
                cin >> triangle[i][j];
        }
        cal_path(triangle, cache, 0,0);
        int result = num_path(triangle, cache, cache2, 0,0);
        cout << result << endl;
    }
    return 0;
}

void printCache(const vector<vector<int>>& cache)
{
    for (vector<int> i : cache)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
}

int cal_path(const vector<vector<int>>& triangle, vector<vector<int>>& cache, int p, int q)
{
    int& ret = cache[p][q];
    if (ret != -1)
        return ret;
    
    // base case
    if (p == triangle.size() -1)
        return ret = triangle[p][q];

    int result = max(cal_path(triangle, cache, p+1, q), cal_path(triangle, cache, p+1, q+1)) + triangle[p][q];
    return ret = result;
}

int num_path(const vector<vector<int>>& triangle, const vector<vector<int>>& cache, vector<vector<int>>& cache2, int p, int q)
{
    int& ret = cache2[p][q];
    if (ret != -1)
        return ret;
    
    // base case
    if (p == triangle.size() - 1)
        return ret = 1;
    
    if (cache[p][q] == cache[p+1][q] + triangle[p][q] && cache[p][q] == cache[p+1][q+1] + triangle[p][q])
        ret = num_path(triangle, cache, cache2, p+1, q) + num_path(triangle, cache, cache2, p+1, q+1);
    else if (cache[p][q] == cache[p+1][q] + triangle[p][q] && cache[p][q] != cache[p+1][q+1] + triangle[p][q])
        ret = num_path(triangle, cache, cache2, p+1, q);
    else if (cache[p][q] != cache[p+1][q] + triangle[p][q] && cache[p][q] == cache[p+1][q+1] + triangle[p][q])
        ret = num_path(triangle, cache, cache2, p+1, q+1);
    
    return ret;
}