struct T {
  long long sum;
  int count;
};

class Solution {
 public:
  int equalToDescendants(TreeNode* root) {
    return dfs(root).count;
  }

 private:
  T dfs(TreeNode* root) {
    if (root == nullptr)
      return T{.sum = 0, .count = 0};
    T left = dfs(root->left);
    T right = dfs(root->right);
    return T{.sum = root->val + left.sum + right.sum,
             .count = left.count + right.count +
                      (root->val == left.sum + right.sum ? 1 : 0)};
  }
};
