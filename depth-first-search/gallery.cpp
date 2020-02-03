#include <iostream>
#include <vector>

using namespace std;

void set_camera(vector<vector<int>>& graph, vector<int>& degree, vector<int>& colored, vector<int>& dominated, int here)
{
    if (degree[here] == 1)
        return;
    int g = degree.size();
    for (int i=0; i<g; i++)
    {
        if (graph[here][i] && !dominated[i])
        {
            colored[here] = 1;
        }
    }
}

int main(void)
{
    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        int g, h;
        cin >> g >> h;
        int a,b;
        vector<vector<int>> graph(g, vector<int>(g,0));
        vector<int> degree(g,0);
        vector<int> colored(g,0);
        vector<int> dominated(g,0);
        for (int i=0; i<h; i++)
        {
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
            degree[a]++;
            degree[b]++;
        }
    }
    return 0;
}