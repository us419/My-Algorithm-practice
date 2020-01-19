#include <iostream>
#include <vector>

using namespace std;

int asymtiling(vector<int>& cache, int idx);

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        int n;
        cin >> n;
        vector<int> cache(n, -1);
        int result;
        asymtiling(cache, n-1); 
        if (n % 2 == 1)
            if (cache[n-1] - cache[(n-1)/2] >= 0)        
                result = cache[n-1] - cache[(n-1)/2];
            else
                result = cache[n-1] - cache[(n-1)/2] + 1000000007;
        else
        {
            if (cache[n-1] - cache[(n-1)/2] - cache[(n-1)/2-1] >= 0)
                result = cache[n-1] - cache[(n-1)/2] - cache[(n-1)/2-1];
            else if (cache[n-1] - cache[(n-1)/2] - cache[(n-1)/2-1] + 1000000007 >= 0)
                result = cache[n-1] - cache[(n-1)/2] - cache[(n-1)/2-1] + 1000000007;
            else
                result = cache[n-1] - cache[(n-1)/2] - cache[(n-1)/2-1] + 2* 1000000007;
        }
        if (n == 1)
            result = 0;
        if (n == 2)
            result = 0;
        
        cout << result << endl;
    }
}

int asymtiling(vector<int>& cache, int idx)
{
    int& ret = cache[idx];
    if (ret != -1)
        return ret;
    
    if (idx == 0)
        return ret = 1;
    if (idx == 1)
        return ret = 2;

    ret = (asymtiling(cache, idx-1) + asymtiling(cache, idx-2)) % 1000000007;
    return ret;
}