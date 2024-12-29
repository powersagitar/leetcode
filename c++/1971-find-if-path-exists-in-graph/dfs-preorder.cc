#include <list>
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

    bool has_valid_path = false;

    dfs(source, destination, adj_list, has_valid_path);

    return has_valid_path;
  }

private:
  void dfs(const int source, const int destination,
           const vector<list<int>> &adj_list, bool &has_valid_path) {
    if (source == destination) {
      has_valid_path = true;
    }

    if (traversed_.contains(source) || has_valid_path) {
      return;
    }

    traversed_.emplace(source);

    const list<int> &connected_vertices = adj_list[source];

    for (const int vertex : connected_vertices) {
      dfs(vertex, destination, adj_list, has_valid_path);
    }
  }

  unordered_set<int> traversed_;
};
