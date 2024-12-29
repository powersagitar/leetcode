#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));

    for (const auto &edge : edges) {
      const int from = edge.front();
      const int to = edge.back();

      adj_matrix[from][to] = true;
      adj_matrix[to][from] = true;
    }

    return dfs(source, destination, adj_matrix);
  }

private:
  bool dfs(const int source, const int destination,
           const vector<vector<bool>> &adj_matrix) {
    traversed_vertices.insert(source);

    if (source == destination) {
      return true;
    }

    vector<int> connected_vertices;

    for (int i = 0; i < adj_matrix.size(); ++i) {
      if (adj_matrix[source][i]) {
        connected_vertices.emplace_back(i);
      }
    }

    for (int vertex : connected_vertices) {
      if (!traversed_vertices.contains(vertex)) {
        return dfs(vertex, destination, adj_matrix);
      }
    }

    return false;
  }

  unordered_set<int> traversed_vertices;
};
