#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int next_signal(unsigned int& a);
bool isK(const int& k, unsigned int& start_num, unsigned int& start_sig, unsigned int& end_num, unsigned int& end_sig, int& sum);

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        int k, n;
        cin >> k >> n;
        int count = 0;
        int sum = 1984;
        unsigned int start_num = 1983;
        unsigned int start_sig = 1984;
        unsigned int end_num = 1983;
        unsigned int end_sig;
        while (sum < k)
        {
            end_sig = next_signal(end_num);
            sum += end_sig;
        }
        if (sum == k)
            count++;

        for (int i=0; i<n-1; i++)
        {
            if(isK(k, start_num, start_sig, end_num, end_sig, sum))
                count++;
        }
        cout << count << endl;
    }
    return 0;
}

bool isK(const int& k, unsigned int& start_num, unsigned int& start_sig, unsigned int& end_num, unsigned int& end_sig, int& sum)
{
    unsigned int new_start_sig = next_signal(start_num);
    sum -= start_sig;
    start_sig = new_start_sig;
    while (sum < k)
    {
        end_sig = next_signal(end_num);
        sum += end_sig;
    }
    if (sum == k)
        return true;

    return false;
}

int next_signal(unsigned int& a)
{
    a = a * 214013 + 2531011;
    int result = a % 10000 + 1;
    return result;
}