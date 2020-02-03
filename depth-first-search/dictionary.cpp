#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<bool>> adj(26, vector<bool>(26,0));
vector<bool> visited(26,0);
vector<int> order;

void comp(string& str1, string& str2)
{
    int length = (str1.length() < str2.length()) ? str1.length() : str2.length();    // 더 작은 길이 저장
    for (int i=0; i<length; i++)
    {
        if (str1[i] != str2[i])
        {
            adj[str1[i]-'a'][str2[i]-'a'] = 1;
            break;
        }
    }
}

void dfs(int here)
{
    visited[here] = 1;
    for (int i=0; i<26; i++)
    {
        if (adj[here][i] && !visited[i])
        {
            dfs(i);
        }
    }
    order.push_back(here);
}

vector<int> topologicalSort()
{
    order.clear();
    for (int i=0; i<visited.size(); i++)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());
    for (int i=0; i<26; i++)
    {
        for (int j=i+1; j<26; j++)
        {
            if (adj[order[j]][order[i]])
                return vector<int>();
        }
    }
    return order;
}

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        adj = vector<vector<bool>>(26, vector<bool>(26,0));
        visited = vector<bool>(26,0);
        int n;
        cin >> n;
        vector<string> strings(n);
        for (int i=0; i<n; i++)
        {
            cin >> strings[i];
        }
        for (int i=0; i<n-1; i++)
        {
            comp(strings[i], strings[i+1]);
        }
        vector<int> result = topologicalSort();
        if (result.empty())
            cout << "INVALID HYPOTHESIS" << endl;
        else
        {
            for (int i: result)
            {
                cout << (char)(i+'a');
            }
            cout << endl;
        }
        
    }
    return 0;
}