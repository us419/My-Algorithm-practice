#include <iostream>
#include <vector>

using namespace std;

int pivonachi(vector<int>& cache, int k);

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        int k;
        cin >> k;
        vector<int> cache(k,-1);
        int result = pivonachi(cache, k-1);
        cout << result << endl;    
    }
    return 0;
}

int pivonachi(vector<int>& cache, int idx)
{
    int& ret = cache[idx];
    if (ret != -1)
        return ret;
    
    if (idx == 0)
    {
        return ret = 1;
    }
    if (idx == 1)
    {
        return ret = 2;
    }
    ret = (pivonachi(cache, idx-1) + pivonachi(cache, idx-2)) % 1000000007;
    
    return ret;
}