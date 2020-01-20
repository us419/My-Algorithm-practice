#include <iostream>
#include <vector>

using namespace std;

double probDu(const vector<vector<int>>& route, const vector<int>& size, vector<vector<double>>& cache, int town, int day, const int& start);
void printCache(const vector<vector<double>>& cache);
int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n, d, p;
        cin >> n >> d >> p;
        vector<vector<int>> route(n, vector<int>(n,0));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> route[i][j];
        vector<int> size(n,0);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                size[i] += route[i][j];
        }
        vector<vector<double>> cache(n, vector<double>(d,-1));
        int t, q;
        cin >> t;
        vector<int> result_town(t,0);
        for (int i=0; i<t; i++)
            cin >> result_town[i];
        cout.precision(8);
        for (int i : result_town)
        {
            cout << probDu(route, size, cache, i, d, p) << " ";
        }
        cout << endl;
    }
}
void printCache(const vector<vector<double>>& cache)
{
    for (vector<double> i : cache)
    {
        for (double j : i)
            cout << j << " ";
        cout << endl;
    }
}

double probDu(const vector<vector<int>>& route, const vector<int>& size, vector<vector<double>>& cache, int town, int day, const int& start)
{
    // if (day == 0)
    //     return 0;
    double& ret = cache[town][day-1];
    if (ret != -1)
        return ret;

    if (day == 1)
    {
        if (route[town][start] == 1)
        {
            ret = (double)1 / size[start];
            return ret;
        }
        else
            return ret = 0; 
    }

    ret = 0;
    for (int i=0; i<route.size(); i++)
    {
        if (route[town][i] == 1)
        {
            ret += probDu(route, size, cache, i, day-1, start) / size[i];
        }
    }
    return ret;
}