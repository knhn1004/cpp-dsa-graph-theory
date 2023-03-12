using namespace std;
#include <bits/stdc++.h>

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited,
         unordered_set<int> &in_stack) {
  visited[node] = true;
  in_stack.insert(node);
  for (int nbr : adj[node]) {
    if (visited[nbr] && in_stack.count(nbr) && in_stack.size() % 2 == 1) {
      return true;
    }
    if (!visited[nbr] && dfs(nbr, adj, visited, in_stack)) {
      return true;
    }
  }
  in_stack.erase(node);
  return false;
}

bool solve(vector<vector<int>> adj) {
  int n = adj.size();
  vector<bool> visited(n, false);
  unordered_set<int> in_stack;

  for (int node = 0; node < n; node++) {
    if (!visited[node] && dfs(node, adj, visited, in_stack))
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  return 0;
}
