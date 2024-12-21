struct T {
  bool isPerfect;
  int sz;
};

class Solution {
 public:
  int kthLargestPerfectSubtree(TreeNode* root, int k) {
    vector<int> ans;
    dfs(root, ans);
    ranges::sort(ans, greater<>());
    return ans.size() < k ? -1 : ans[k - 1];
  }

 private:
  T dfs(TreeNode* root, vector<int>& ans) {
    if (root == nullptr)
      return {true, 0};
    const auto l = dfs(root->left, ans);
    const auto r = dfs(root->right, ans);
    if (l.isPerfect && r.isPerfect && l.sz == r.sz) {
      const int sz = 1 + l.sz + r.sz;
      ans.push_back(sz);
      return {true, sz};
    }
    return {false, 0};
  }
};
