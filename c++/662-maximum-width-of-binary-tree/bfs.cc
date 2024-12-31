#include <algorithm>
#include <queue>
#include <utility>

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
  int widthOfBinaryTree(TreeNode *root) {
    std::queue<std::pair<TreeNode *, size_t>> queue;
    queue.emplace(root, 0);

    size_t max_width = 1;

    while (!queue.empty()) {
      const size_t left_index = queue.front().second;
      const size_t right_index = queue.back().second;
      const size_t level_width = right_index - left_index + 1;
      max_width = std::max(level_width, max_width);

      const size_t level_size = queue.size();

      for (size_t i = 0; i < level_size; ++i) {
        const TreeNode *const node = queue.front().first;
        const size_t index = queue.front().second;
        queue.pop();

        if (node->left) {
          queue.emplace(node->left, index * 2 + 1);
        }

        if (node->right) {
          queue.emplace(node->right, index * 2 + 2);
        }
      }
    }

    return max_width;
  }
};
