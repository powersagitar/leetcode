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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vals;

    inorderDFS(root, vals);

    return vals;
  }

private:
  void inorderDFS(const TreeNode *const node, vector<int> &vals) {
    if (!node) {
      return;
    }

    inorderDFS(node->left, vals);
    vals.emplace_back(node->val);
    inorderDFS(node->right, vals);
  }

  void preorderDFS(const TreeNode *const node, vector<int> &vals) {
    if (!node) {
      return;
    }

    vals.emplace_back(node->val);
    preorderDFS(node->left, vals);
    preorderDFS(node->right, vals);
  }

  void postorderDFS(const TreeNode *const node, vector<int> &vals) {
    if (!node) {
      return;
    }

    postorderDFS(node->left, vals);
    postorderDFS(node->right, vals);
    vals.emplace_back(node->val);
  }
};
