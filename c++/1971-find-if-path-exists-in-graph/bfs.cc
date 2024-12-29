#include <list>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    vector<list<int>> adj_list(n);

    for (const auto &edge : edges) {
      const int from = edge.front();
      const int to = edge.back();

      adj_list[from].emplace_back(to);
      adj_list[to].emplace_back(from);
    }

    // bfs
    queue<int> to_traverse;
    unordered_set<int> traversed;
    to_traverse.emplace(source);

    while (!to_traverse.empty()) {
      const int vertex = to_traverse.front();
      to_traverse.pop();
      traversed.emplace(vertex);

      if (vertex == destination) {
        return true;
      }

      for (const int next_vertex : adj_list[vertex]) {
        if (!traversed.contains(next_vertex)) {
          to_traverse.emplace(next_vertex);
        }
      }
    }

    return false;
  }
};
