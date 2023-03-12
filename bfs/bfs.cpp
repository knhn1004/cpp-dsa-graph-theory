#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  list<int> *adj;

public:
  Graph(int v) {
    this->V = v;
    this->adj = new list<int>[V];
  }

  ~Graph() { delete[] this->adj; }

  void addEdge(int i, int j, bool undir = true) {
    adj[i].push_back(j);
    if (undir) {
      adj[j].push_back(i);
    }
  }

  void bfs(int src) {
    queue<int> q;
    vector<bool> visited(V, false);
    q.push(src);
    visited[src] = true;

    int cur;
    while (!q.empty()) {
      cur = q.front();
      cout << cur << " ";
      q.pop();
      for (int nbr : adj[cur]) {
        if (!visited[nbr]) {
          visited[nbr] = true;
          q.push(nbr);
        }
      }
    }
    cout << endl;
  }
};

int main() {

  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(3, 5);
  g.addEdge(5, 6);
  g.addEdge(4, 5);
  g.addEdge(0, 4);
  g.addEdge(3, 4);

  g.bfs(0);

  return 0;
}
