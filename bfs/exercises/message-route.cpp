#include <bits/stdc++.h>
using namespace std;

int messageRoute(int n, vector<vector<int>> edges) {
  vector<vector<int>> adj(n, vector<int>());
  vector<bool> visited(n, false);
  queue<int> q;

  for (auto e : edges) {
    int i = e[0], j = e[1];
    // convert 1~n to 0~n-1

    adj[i - 1].push_back(j - 1);
    adj[j - 1].push_back(i - 1);
  }

  int level = 1, levelSize = 1, nextLevelSize = 0, cur;
  q.push(0);
  while (!q.empty()) {
    for (int i = 0; i < levelSize; i++) {
      cur = q.front();
      q.pop();
      visited[cur] = true;

      if (cur == n - 1)
        return level;
      for (int nbr : adj[cur]) {
        if (!visited[nbr]) {
          q.push(nbr);
          nextLevelSize++;
        }
      }
    }
    levelSize = nextLevelSize;
    nextLevelSize = 0;
    level++;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cout << messageRoute(4, {{1, 2}, {4, 1}, {2, 3}, {3, 1}}) << endl;

  return 0;
}
