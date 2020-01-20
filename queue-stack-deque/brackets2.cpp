#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool bracket(stack<char>& A, const string str);
bool match(char a, char b);

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        string str;
        cin >> str;
        stack<char> A;
        if (bracket(A,str))
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
bool match(char a, char b)
{
    if (a=='(' && b==')')
        return true;
    else if (a=='{' && b=='}')
        return true;
    else if (a=='[' && b==']')
        return true;
    else
    {
        return false;
    }
}
bool bracket(stack<char>& A, const string str)
{
    for (int i=0; i<str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            A.push(str[i]);
        }
        else
        {
            if (A.empty())
                return false;
            if (match(A.top(),str[i]))
            {
                A.pop();
            }
            else
                return false;
        }
    }
    if (A.empty())
        return true;
    else
    {
        return false;
    }
    
}