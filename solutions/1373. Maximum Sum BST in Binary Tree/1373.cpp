class Solution {
 public:
  int maxSumBST(TreeNode* root) {
    int ans = 0;

    dfs(root, ans);

    return ans;
  }

 private:
  tuple<int, int, int, bool> dfs(TreeNode* root, int& ans) {
    if (!root) return {INT_MAX, INT_MIN, 0, true};

    auto [leftMin, leftMax, leftSum, leftValid] = dfs(root->left, ans);
    auto [rightMin, rightMax, rightSum, rightValid] = dfs(root->right, ans);
    bool valid =
        leftValid && rightValid && root->val > leftMax && root->val < rightMin;
    int sum = valid ? root->val + leftSum + rightSum : -1;
    ans = max(ans, sum);

    return {min(root->val, leftMin), max(root->val, rightMax), sum, valid};
  }
};
