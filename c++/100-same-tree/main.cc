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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // p xor q is nullptr
    if ((!p && q) || (p && !q)) {
      return false;
    } else if (!p && !q) {
      return true;
    }

    if (p->val != q->val) {
      return false;
    }

    const bool left = isSameTree(p->left, q->left);
    const bool right = isSameTree(p->right, q->right);

    return left && right;
  }
};
