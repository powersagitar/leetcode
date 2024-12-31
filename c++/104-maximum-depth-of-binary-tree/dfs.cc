#include <algorithm>
#include <cstddef>
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
  int maxDepth(TreeNode *root) { return dfs(root, 1); }

private:
  size_t dfs(const TreeNode *const node, const size_t depth) {
    if (!node) {
      return depth - 1;
    }

    return std::max(dfs(node->left, depth + 1), dfs(node->right, depth + 1));
  }
};
