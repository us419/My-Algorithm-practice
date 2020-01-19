#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>

using namespace std;

int difficulty(const vector<int>& int_pi, vector<int>& cache, int idx);
int calcul(const vector<int>& int_pi, int idx, int length);
void printCache(vector<int>& cache);

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        string pi;
        cin >> pi;
        int n = pi.length();
        vector<int> int_pi(n, 0);
        vector<int> cache(n, -1);
        for (int i=0; i<n; i++)
        {
            int_pi[i] = pi[i] - '0'; // ascii값으로 출력되는 거 막기
        }
        cache[n-1] = 999;
        cache[n-2] = 999;
        // printCache(int_pi);
        int result = difficulty(int_pi, cache, 0);
        // printCache(cache);
        // cout << endl;
        cout << result << endl;
    }
    return 0;
}
void printCache(vector<int>& cache)
{
    for (int i=0; i<cache.size(); i++)
    {
        cout << cache[i] << " ";
    }
    cout << endl;
}
int difficulty(const vector<int>& int_pi, vector<int>& cache, int idx)
{
    if (idx >= int_pi.size())
        return 0;

    int& ret = cache[idx];
    if (ret != -1)
        return ret;
    
    int a = calcul(int_pi, idx, 3) + difficulty(int_pi, cache, idx+3);
    int b = calcul(int_pi, idx, 4) + difficulty(int_pi, cache, idx+4);
    int c = calcul(int_pi, idx, 5) + difficulty(int_pi, cache, idx+5);
    // cout << "a is " << a << endl;
    // cout << "b is " << b << endl;
    // cout << "c is " << c << endl;
    // idx를 기준으로 3칸을 나눌지 4칸을 나눌지 5칸을 나눌지, 비교후 셋중 가장 작은 값을 받는다.
    ret = min(min(a, b), c);
    return ret;
}

int calcul(const vector<int>& int_pi, int idx, int length)
{
    // index가 벗어나는 경우
    if (idx + length > int_pi.size())
        return 9999;

    // case 1
    for (int i=0; i<length-1; i++)
    {
        if (int_pi[idx+i] != int_pi[idx+i+1])
            break;
        if (i == length-2)
            return 1;
    }

    // case 2
    for (int i=0; i<length-1; i++)
    {
        if (int_pi[idx+i] - int_pi[idx+i+1] != 1)
            break;
        if (i == length-2)
            return 2;
    }

    for (int i=0; i<length-1; i++)
    {
        if (int_pi[idx+i] - int_pi[idx+i+1] != -1)
            break;
        if (i == length-2)
            return 2;
    }

    // case 3
    const int first_one = int_pi[idx];
    const int second_one = int_pi[idx+1];
    for (int i=0; i<length; i++)
    {
        if (i%2 == 0 && int_pi[idx+i] != first_one)
            break;
        if (i%2 == 1 && int_pi[idx+i] != second_one)
            break;
        if (i == length-1)
            return 4;
    }

    // case 4
    const int d = first_one - second_one;
    for (int i=0; i<length-1; i++)
    {
        if (int_pi[idx+i] - int_pi[idx+i+1] != d)
            break;
        if (i == length-2)
            return 5;
    }

    // case 5
    return 10;
}