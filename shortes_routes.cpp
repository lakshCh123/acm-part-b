
#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;
void dfs(int node, long long dist,vector<vector<pair<int,int>>>& graph,vector<int>& visited) {
    ans[node] = min(ans[node], dist);
    visited[node] = 1;
    for (auto it : graph[node]) {
        int nextNode = it.first;
        int weight = it.second;
        if (!visited[nextNode]) {
            dfs(nextNode, dist + weight, graph, visited);
        }
    }
    visited[node] = 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >>u>> v>> weight;
        graph[u].push_back({v, weight});
    }
    ans.resize(n + 1, LLONG_MAX);
    vector<int> visited(n + 1, 0);
    dfs(1, 0, graph, visited);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
