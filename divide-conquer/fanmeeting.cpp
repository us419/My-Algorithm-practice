#include <iostream>
#include <vector>

using namespace std;

bool match(const string& member, const string& fan, int start_idx, int end_idx, const int diff)
{
    int n = member.size();
    // base case
    if (start_idx == end_idx)
    {
        if ((member[start_idx] == 'M') && (fan[start_idx + diff] == 'M'))
            return false;
        else
            return true;
    }
        
    int middle = (start_idx + end_idx) / 2;
    bool merge = match(member, fan, start_idx, middle, diff) && match(member, fan, middle+1, end_idx, diff);

    return merge;
}

int main(void)
{
    int n_test;
    int n, m, count;
    string member;
    string fan;
    cin >> n_test;

    while(n_test--)
    {
        cin >> member;
        cin >> fan;
        n = member.size();
        m = fan.size();
        count = 0;
        for(int i=0; i<m-n+1; i++)
        {
            if (match(member, fan, 0, n-1, i))
                count++;
        }
        cout << count << endl;
    }
    
    return 0;
}

/*
 * 위 방법대로 하면 시간초과 뜸
 * 사실 위 문제는 큰 두수의 곱셈 문제와 같음(자리 올림 없이하면)
 * 카라츠바 알고리즘을 적용하면 쉽게 해결 가능
 */