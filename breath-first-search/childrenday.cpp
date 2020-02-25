#include <iostream>
#include <vector>

using namespace std;

int preCalc(vector<vector<int>>& chart, const vector<int>& D, int n, int m)
{
    
}

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        string d;
        int n,m;
        cin >> d >> n >> m;
        int d_length = d.length();
        vector<int> D;
        for (int i=0; i<d_length; i++)
            D.push_back(d[i] - '0');
        vector<vector<int>> chart(n,vector<int>(d_length, 0));
    }
    return 0;
}