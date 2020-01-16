#include <iostream>
#include <vector>

using namespace std;

int longest_sequence(const vector<int>& int_list, vector<int>& cache, int pos);

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n;
        cin >> n;
        vector<int> int_list(n);
        for (int i=0;i<n;i++)
        {
            cin >> int_list[i];
        }
        vector<int> cache(n,-1);
        cache[n-1] = 1;
        for (int i=0; i<n; i++)
        {
            if (cache[i] == -1)
                longest_sequence(int_list, cache, i);
        }
        int result = 0;
        for (int i : cache)
            if (result < i)
                result = i;
        cout << result << endl;
    }
    return 0;
}

int longest_sequence(const vector<int>& int_list, vector<int>& cache, int pos)
{
    int& ret = cache[pos];
    if (ret != -1)
        return ret;
    
    int value = int_list[pos];
    int temp = 0;
    int max_length = 1;
    for (int i=pos+1; i<int_list.size(); i++)
    {
        if (value < int_list[i])
        {
            temp = longest_sequence(int_list, cache, i) + 1;
            if (max_length < temp)
            {
                max_length = temp;
            }
        }
    }
    ret = max_length;
    return ret;
}
