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
  bool isSymmetric(TreeNode *root) {
    return dfs(root->left, root->right);
  }

private:
  bool dfs(const TreeNode *const left, const TreeNode *const right) {
    if (!left && !right) {
      return true;
    } else if (!left || !right) {
      return false;
    }

    if (left->val != right->val) {
      return false;
    }

    const bool outer = dfs(left->left, right->right);
    const bool inner = dfs(left->right, right->left);

    return outer && inner;
  }
};
