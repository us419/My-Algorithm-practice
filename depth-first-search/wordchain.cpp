#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<string> graph[26][26];
vector<int> indegree;
vector<int> outdegree;
vector<int> order;

void makeGraph(vector<string>& input_string)
{
    for (string i: input_string)
    {
        adj[i.front()-'a'][i.back()-'a']++;
        outdegree[i.front()-'a']++;
        indegree[i.back()-'a']++;
        graph[i.front()-'a'][i.back()-'a'].push_back(i);
    }
}

pair<int,int> isEuler()
{
    vector<int> start_node;
    vector<int> end_node;
    for (int i=0; i<26; i++)
    {
        if (indegree[i] == outdegree[i])
            continue;
        else if (indegree[i] == outdegree[i] + 1)
            end_node.push_back(i);
        else if (indegree[i]+1 == outdegree[i])
            start_node.push_back(i);
        else
            return make_pair(-1,-1);
    }
    if (start_node.empty() && end_node.empty())
        return make_pair(0,0);
    if (start_node.size()==1 && end_node.size()==1)
        return make_pair(start_node.back(), end_node.back());
    return make_pair(-1,-1);
}

void findEulerCircuit(int here)
{
    for (int i=0; i<adj[here].size(); i++)
    {
        if (adj[here][i])
        {
            adj[here][i]--;
            findEulerCircuit(i);
        }
    }
    order.push_back(here);
}

void printCircuit()
{
    pair<int,int> temp = isEuler();
    string output;
    if (temp.first == -1 && temp.second == -1)
        cout << "IMPOSSIBLE" << endl;
    else if (temp.first == 0 && temp.second == 0)
    {
        for(int i=0; i<26; i++)
        {
            if (indegree[i])
            {
                findEulerCircuit(i);
                reverse(order.begin(), order.end());
                for (int j=1; j<order.size(); j++)
                {
                    if(!output.empty())
                        output += " ";
                    output += graph[order[j-1]][order[j]].back();
                    graph[order[j-1]][order[j]].pop_back();
                }
                cout << output << endl;
                break;
            }
        }
    }
    else
    {
        findEulerCircuit(temp.first);
        reverse(order.begin(), order.end());
        for (int j=1; j<order.size(); j++)
        {
            if(!output.empty())
                output += " ";
            output += graph[order[j-1]][order[j]].back();
            graph[order[j-1]][order[j]].pop_back();
        }
        cout << output << endl;
    }
    
}

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        int n;
        cin >> n;
        vector<string> input_string(n);
        adj = vector<vector<int>>(26, vector<int>(26,0));
        indegree = vector<int>(26,0);
        outdegree = vector<int>(26,0);
        order.clear();
        for (int i=0; i<n; i++)
        {
            cin >> input_string[i];
        }
        for (int i=0; i<26; i++)
            for (int j=0; j<26; j++)
                graph[i][j].clear();
        makeGraph(input_string);
        printCircuit();
    }
    return 0;
}