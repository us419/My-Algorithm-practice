#include <iostream>
#include <vector>

using namespace std;

double climb(vector<vector<double>>& cache, int n, int m);

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<double>> cache(n, vector<double>(m,-1));
        double result = climb(cache, n, m);
        cout.precision(10);
        cout << result << endl;
    }
    return 0;
}

double climb(vector<vector<double>>& cache, int n, int m)
{
    // base case
    if (n <= 0)
        return 1;
    if (m <= 0)
        return 0;

    double& ret = cache[n-1][m-1];
    if (ret != -1)
        return ret;
    
    ret = 0.25 * climb(cache, n-1, m-1) + 0.75 * climb(cache, n-2, m-1);
    return ret;
}