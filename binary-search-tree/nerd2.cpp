#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

bool isDominated(map<int,int>& coord, int p, int q)
{
    map<int,int>::iterator it = coord.lower_bound(p);
    if (it == coord.end())
        return false;
    if (it->second > q)
        return true;
    else
    {
        return false;
    }
}

void removeDominate(map<int,int>& coord, int p, int q)
{
    map<int,int>::iterator it = coord.lower_bound(p);
    if (it == coord.begin())
        return;
    it--;

    while(true)
    {
        if (it->second > q)
            return;        
        if (it == coord.begin())
        {
            coord.erase(it);
            return;
        }    
        else
        {
            map<int,int>::iterator jt = it;
            jt--;
            coord.erase(it);
            it = jt;
        }
    }

}

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int n;
        cin >> n;
        int sum = 0;
        map<int,int> coord;
        for (int k=0; k<n; k++)
        {
            int p,q;
            cin >> p >> q;     // 많은 입력으로 인해 scanf로 시간절약
            if(isDominated(coord, p, q))
                sum += coord.size();
            else
            {
                removeDominate(coord, p, q);
                coord.insert(pair<int,int>(p,q));
                sum += coord.size();
            }
        }
        cout << sum << endl;
    }
}