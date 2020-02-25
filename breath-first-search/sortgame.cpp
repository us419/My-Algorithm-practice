#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

map<vector<int>, int> distance_cache;

void bfs(int n)
{
    vector<int> sorted_list(n,0);
    for (int i=0; i<n; i++)
        sorted_list[i] = i;
    queue<vector<int>> q;
    
    distance_cache[sorted_list] = 0;
    q.push(sorted_list);
    while(!q.empty())
    {
        vector<int> current_list = q.front();
        q.pop();
        int depth = distance_cache[current_list];
        for (int i=0; i<n; i++)
        {
            for (int j=i+2; j<=n; j++)
            {
                vector<int> temp = current_list;
                reverse(temp.begin()+i, temp.begin()+j);
                if (distance_cache.count(temp) == 0)
                {
                    distance_cache[temp] = depth + 1;
                    q.push(temp);
                }
            }
        }
    }
}

void printDepth(vector<int>& raw_list)
{
    int n = raw_list.size();
    vector<int> temp(n,0);
    int order;
    for (int i=0; i<n; i++)
    {
        order = 0;
        for (int j=0; j<n; j++)
        {
            if (raw_list[i] > raw_list[j])
                order++;
        }
        temp[i] = order;
    }
    cout << distance_cache[temp] << endl;
}

int main(void)
{
    int n_test;
    cin >> n_test;
    for (int i=1; i<=8; i++)
        bfs(i);
    while (n_test--)
    {
        int n;
        cin >> n;
        vector<int> raw_list(n,0);
        for (int i=0; i<n; i++)
            cin >> raw_list[i];
        printDepth(raw_list);
    }
    return 0;
}