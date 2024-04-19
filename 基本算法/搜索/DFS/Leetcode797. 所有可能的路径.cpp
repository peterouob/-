#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> path;
vector<vector<int>> result;

void dfs(vector<vector<int>> &graph, int x)
{
    if (x == graph.size() - 1)
    {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < graph[x].size(); i++)
    {
        path.push_back(graph[x][i]);
        dfs(graph, graph[x][i]);
        path.pop_back();
    }
}

int main()
{
    path.push_back(0);
    dfs(graph, 0);
    for (auto &r : result)
    {
        printf("%d", r);
    }
}