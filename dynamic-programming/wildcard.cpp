#include <iostream>
#include <vector>
#include <typeinfo>
#include <cassert>

using namespace std;

bool isMatch(const string& wild, const string& obj)
{
    int pos = 0;
    while(pos < wild.size() && pos < obj.size() && (wild[pos] == '?' || wild[pos] == obj[pos]))
    {
        pos++;
    }
    // while문이 왜 끝났는지 확인
    // 1. pos == wild.size()
    // 2. pos == obj.size()
    // 3. wild[0] == '*'
    // 4. 문자 비교 결과 다름

    // case 1
    if (pos == wild.size())
    {
        return pos == obj.size();
    }

    // case 2
    if (pos == obj.size())
    {
        for (char c : wild.substr(pos))
            if (c != '*')
                return false;
        return true;
    }

    // case 3
    if (wild[pos] == '*')
    {
        for (int i=0; i+pos <= obj.size(); i++)
            if (isMatch(wild.substr(pos+1), obj.substr(i+pos)))
                return true;
    }

    // case 4
    return false;
}
int main(void)
{
    int n_test, n;
    cin >> n_test;
    string wild;
    while(n_test--)
    {
        cin >> wild;
        cin >> n;
        vector<string> filename(n);
        vector<string> result;
        for (int i=0; i<n; i++)
        {
            cin >> filename[i];
        }
        for (string obj : filename)
        {
            if (isMatch(wild, obj))
                result.push_back(obj);
        }
        while(result.size() > 0)
        {
            for (int i=0; i<result.size()-1; i++)
            {
                if (result[i].compare(result[i+1]) < 0)
                {
                    string temp = result[i];
                    result[i] = result[i+1];
                    result[i+1] = temp;
                }
            }
            cout << result.back() << endl;
            result.pop_back();
        }
    }
    return 0;
}

