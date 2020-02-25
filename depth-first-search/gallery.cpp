#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000];
vector<bool> visited;

const int INSTALLED = 0;
const int WATCHED = 1;
const int UNWATCHED = 2;

int installed = 0;

int dfs(int here)
{
    visited[here] = 1;
    int children[3] = {0,0,0};
    for (int i=0; i<adj[here].size(); i++)
    {
        int there = adj[here][i];
        if (!visited[there])
            children[dfs(there)]++;
    }
    if (children[UNWATCHED])
    {
        installed++;
        return INSTALLED;
    }
    if (children[INSTALLED])
        return WATCHED;
    return UNWATCHED;
}

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        installed = 0;
        int g, h;
        cin >> g >> h;
        visited = vector<bool>(g,0);
        for (int i=0; i<1000; i++)
            adj[i].clear();
        int a,b;
        for (int i=0; i<h; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i=0; i<g; i++)
        {
            if (!visited[i] && dfs(i) == UNWATCHED)
                installed++;
        }
        cout << installed << endl;
    }
    return 0;
}