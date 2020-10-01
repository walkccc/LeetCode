class Solution {
 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> ans;
    unordered_map<int, int> count;
    int maxCount = 0;

    function<int(TreeNode*)> sumDownFrom = [&](TreeNode* root) {
      if (!root) return 0;

      const int sum =
          root->val + sumDownFrom(root->left) + sumDownFrom(root->right);
      ++count[sum];

      return sum;
    };

    sumDownFrom(root);

    for (const auto& [_, freq] : count)
      maxCount = max(maxCount, freq);

    for (const auto& [sum, freq] : count)
      if (freq == maxCount)
        ans.push_back(sum);

    return ans;
  }
};