#include <bits/stdc++.h>
using namespace std;
bool dfs_helper(vector<int> graph[], int node, int *visited, int parent,
                int color) {
  visited[node] = color;
  for (auto nbr : graph[node]) {
    if (visited[nbr] == 0) {
      int subprob = dfs_helper(graph, nbr, visited, node, 3 - color);
      if (subprob == false) {
        return false;
      }
    } else if (nbr != parent && color == visited[nbr]) {
      return false;
    }
  }
  return true;
}

bool dfs(vector<int> graph[], int N) {
  int visited[N] = {0};
  // 0: not visited, 1: visited  and colored 1, 2: visited and colored 2
  int color = 1;
  bool ans = dfs_helper(graph, 0, visited, -1, color);

  for (int i = 0; i < N; i++) {
    cout << i << " - Color: " << visited[i] << endl;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> graph[N];
  while (M--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // BFS or DFS, by coloring the nodes at each step (current node has color 1,
  // its neighbors have color 2, and so on)
  if (dfs(graph, N)) {
    cout << "Bipartite" << endl;
  } else {
    cout << "Not Bipartite" << endl;
  }

  return 0;
}
