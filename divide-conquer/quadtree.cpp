#include <iostream>
#include <string>

using namespace std;

string reverse(string::iterator& it)
{
    char first_char = *it;
    it++;
    // base case
    if (first_char != 'x')
        return string(1, first_char);

    // recursion
    else
    {
        string left_up = reverse(it);
        string right_up = reverse(it);
        string left_down = reverse(it);
        string right_down = reverse(it);
        
        string merge = string("x") + left_down + right_down + left_up + right_up;
        return merge;
    }
    
}
int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        string input_quad;
        cin >> input_quad;
        string::iterator it = input_quad.begin();
        cout << reverse(it) << endl;
    }
    return 0;
}

