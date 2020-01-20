#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int next_signal(const int& a);
bool isK(const int& k, int& before_num, int& end_num, int& sum);

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        int k, n;
        int a = 1983;
        int b = next_signal(a);
        int c = next_signal(b);
        int d = next_signal(c);
        cout << b%10000 + 1 << " " << c%10000+1 << " " << d%10000+1 << endl;
    //     cin >> k >> n;
    //     int count = 0;
    //     int sum = 1984;
    //     int start_num = 1984;
    //     int end_num;
    //     while (sum < k)
    //     {
    //         end_num = next_signal(end_num);
    //         sum += end_num;
    //     }
    //     if (sum == k)
    //         count++;
    //     if (sum > k)
    //         sum -= end_num;
    //     for (int i=0; i<n-1; i++)
    //     {
    //         if(isK(k, start_num, end_num, sum))
    //             count++;
    //     }
    //     cout << count << endl;
    }
    return 0;
}

bool isK(const int& k, int& before_num, int& end_num, int& sum)
{
    cout << "before_num : " << before_num << endl;
    cout << "end_num : " << end_num << endl;
    cout << "sum is " << sum << endl;
    int start_num = next_signal(before_num);
    sum -= before_num;
    before_num = start_num;
    while (sum < k)
    {
        end_num = next_signal(end_num);
        sum += end_num;
    }
    if (sum == k)
        return true;

    sum -= end_num;
    return false;
}

int next_signal(const int& a)
{
    int result = a * 214013 + 2531011;
    return result;
}