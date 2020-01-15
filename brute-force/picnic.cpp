#include <iostream>
#include <array>

using namespace std;
int count_num(int n, array<bool, 10>& taken, const bool (&friends)[10][10]);
int main(void)
{
    int num_testcase = 0;
    cin >> num_testcase;

    int num, m, i, j, result;
    bool friends[10][10];
    fill_n(friends[0], 100, false);
    array<bool, 10> taken;
    taken.fill(false);

    while(num_testcase--)
    {
        cin >> num >> m;
        for (int p=0; p<m; p++)
        {
            cin >> i >> j;
            friends[i][j] = true;
            friends[j][i] = true;
        }
        result = count_num(num, taken, friends);
        cout << result << endl;
        fill_n(friends[0], 100, false);
    }
    return 0;
}

int count_num(int n, array<bool, 10>& taken, const bool (&friends)[10][10])
{
    int count = 0;
    // base case
    int first_free = -1;
    for (int i=0; i<n; i++)
    {
        if (!taken[i])
        {
            first_free = i;
            break;
        }
    }
    if (first_free == -1)
        return 1;

    // recursion
    for (int i=first_free+1; i < n; i++)
    {
        if (!taken[i] && friends[first_free][i])
        {
            taken[first_free] = taken[i] = true;
            count += count_num(n, taken, friends);
            taken[first_free] = taken[i] = false;
        }
    }
    return count;
}

