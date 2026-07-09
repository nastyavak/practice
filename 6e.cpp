#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> used;

void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    used.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int components = 0;
    for (int v = 1; v <= n; v++) {
        if (!used[v]) {
            dfs(v);
            components++;
        }
    }