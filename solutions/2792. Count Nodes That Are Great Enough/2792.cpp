class Solution {
 public:
  int countGreatEnoughNodes(TreeNode* root, int k) {
    int ans = 0;
    dfs(root, k, ans);
    return ans;
  }

 private:
  multiset<int> dfs(TreeNode* root, int k, int& ans) {
    if (root == nullptr)
      return {};

    multiset<int> kSmallest = dfs(root->left, k, ans);
    multiset<int> kSmallestRight = dfs(root->right, k, ans);
    kSmallest.merge(kSmallestRight);

    if (kSmallest.size() > k)
      kSmallest.erase(next(kSmallest.begin(), k), kSmallest.end());
    if (kSmallest.size() == k && root->val > *kSmallest.rbegin())
      ++ans;

    kSmallest.insert(root->val);
    return kSmallest;
  }
};
