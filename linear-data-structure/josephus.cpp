#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n,k;
        cin >> n >> k;
        list<int> circular_list;
        for (int i=1; i<=n; i++)
            circular_list.push_back(i);
        list<int>::iterator it = circular_list.begin();
        while (n > 2)
        {
            it = circular_list.erase(it);
            if (it == circular_list.end())
                it = circular_list.begin();
            for (int i=0; i<k-1; i++)
            {   
                it++;
                if (it == circular_list.end())
                    it = circular_list.begin();
            }
            n--;
        }
        cout << circular_list.front() << " " << circular_list.back() << endl;
    }
    return 0;
}