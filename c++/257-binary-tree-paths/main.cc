#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> paths;
    dfs(root, vector<int>{}, paths);
    return paths;
  }

private:
  void dfs(const TreeNode *const node, vector<int> traversed,
           vector<string> &paths) {
    if (!node) {
      return;
    }

    traversed.emplace_back(node->val);

    dfs(node->left, traversed, paths);
    dfs(node->right, traversed, paths);

    // is leaf
    if (!node->left && !node->right) {
      stringstream path;

      copy(traversed.begin(), traversed.end(),
           ostream_iterator<int>(path, "->"));

      string path_str = path.str();

      paths.emplace_back(path_str.substr(0, path_str.length() - 2));
    }
  }
};
