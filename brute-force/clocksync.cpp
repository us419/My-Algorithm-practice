#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;
class switches
{
    private:
        array<int, 5> clock_list;
    public:
        int n_turn_on = 0;

        switches(int a, int b, int c, int d, int e)
        {
            int temp[5] = {a,b,c,d,e};
            for (int i=0;i<5;i++)
                clock_list[i] = temp[i];
        }

        void turn_on(array<int, 16>& clocks)
        {
            for (int clock_idx : clock_list)
            {
                if (clock_idx == -1)
                    break;
                clocks[clock_idx] += 3;
                if (clocks[clock_idx] == 15)
                    clocks[clock_idx] = 3;
            }
            n_turn_on += 1;
        }
        void turn_off(array<int, 16>& clocks)
        {
            for (int clock_idx : clock_list)
            {
                if (clock_idx == -1)
                    break;
                clocks[clock_idx] -= 3;
                if (clocks[clock_idx] == 0)
                    clocks[clock_idx] = 12;
            }
            n_turn_on -= 1;
        }
};

int set_clocks(array<switches, 10>& switch_list, array<int, 16>& clocks, int switch_idx)
{
    bool ok = true;
    int count = 0;
    int result = 1000;

    // base case
    for (int clock : clocks)
    {
        if (clock != 12)
        {
            ok = false;
            break;
        }
    }

    for (switches _switch : switch_list)
        count += _switch.n_turn_on;
    if (count >= 30)
        return 999;
    if (ok)
        return count;

    // recursion
    for (int idx=switch_idx; idx<switch_list.size(); idx++)
    {
        if (switch_list[idx].n_turn_on == 3)
            continue;
        switch_list[idx].turn_on(clocks);
        result = min(set_clocks(switch_list, clocks, idx), result);
        switch_list[idx].turn_off(clocks);
    }
    return result;
}

int main(void)
{
    int n_test;
    int result;
    cin >> n_test;
    switches switch0(0,1,2,-1,-1);
    switches switch1(3,7,9,11,-1);
    switches switch2(4,10,14,15,-1);
    switches switch3(0,4,5,6,7);
    switches switch4(6,7,8,10,12);
    switches switch5(0,2,14,15,-1);
    switches switch6(3,14,15,-1,-1);
    switches switch7(4,5,7,14,15);
    switches switch8(1,2,3,4,5);
    switches switch9(3,4,5,9,13);
    array<switches, 10> switch_list{switch0,switch1,switch2,switch3,switch4,switch5,switch6,switch7,switch8,switch9};
    while(n_test--)
    {
        array<int, 16> clocks;
        for (int i=0; i<16; i++)
            cin >> clocks[i];
        result = set_clocks(switch_list, clocks, 0);
        if (result == 999)
            result = -1;
        cout << result << endl;
    }

    return 0;
}