#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int rse(const vector<int>& sequence, int start_idx, int end_idx);
int grouping(const vector<int>& sequence, vector<vector<int>>& cache, int idx, int remained_s);
void printCache(const vector<vector<int>>& cache);

int main(void)
{
    int n_test;
    cin >> n_test;

    // vector<int> test = {1,4,7,8,9,10,11,13,16};
    // cout << rse(test, 2,5) << endl;
    while (n_test--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> sequence(n,0);
        for (int i=0; i<n; i++)
        {
            cin >> sequence[i];
        }
        sort(sequence.begin(), sequence.end());
        vector<vector<int>> cache(n, vector<int>(s,-1));
        int result = grouping(sequence, cache, 0, s);
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
int rse(const vector<int>& sequence, int start_idx, int end_idx)
{
    int sum = 0;
    for (int i=start_idx; i<end_idx+1; i++)
    {
        sum += sequence[i];
    }
    float x = float(sum) / (end_idx-start_idx+1);
    int int_x = round(x);
    int rse = 0;
    for (int i=start_idx; i<end_idx+1; i++)
    {
        rse += pow(sequence[i]-int_x, 2);
    }
    return rse;
}
int grouping(const vector<int>& sequence, vector<vector<int>>& cache, int idx, int remained_s)
{
    int n = sequence.size();
    // base case
    if (idx == n)
    {
        return 0;
    }

    if (remained_s == 0)
    {
        return 99999999;
    }
    int& ret = cache[idx][remained_s-1];
    if (ret != -1)
    {
        return ret;
    }

    ret = 99999999;
    for (int i=idx; i<n; i++)
    {
        ret = min(ret, rse(sequence, idx, i) + grouping(sequence, cache, i+1, remained_s-1));
    }

    return ret;
}