#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited,
         int color = 1) {

  visited[node] = color;
  for (int nbr : adj[node]) {
    if (!visited[nbr]) {
      if (!dfs(nbr, node, adj, visited, 3 - color)) {
        return false;
      }
    } else if (nbr != parent && color == visited[nbr]) {
      return false;
    }
  }
  return true;
}

bool isBipartite(vector<vector<int>> adj) {
  int n = adj.size();
  vector<int> visited(n, 0);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      if (!dfs(i, -1, adj, visited)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
