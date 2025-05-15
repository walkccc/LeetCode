class Solution {
 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> ans;
    unordered_map<int, int> count;
    int maxCount = 0;

    sumDownFrom(root, count);

    for (const auto& [_, freq] : count)
      maxCount = max(maxCount, freq);

    for (const auto& [sum, freq] : count)
      if (freq == maxCount)
        ans.push_back(sum);

    return ans;
  }

 private:
  int sumDownFrom(TreeNode* root, unordered_map<int, int>& count) {
    if (root == nullptr)
      return 0;

    const int sum = root->val + sumDownFrom(root->left, count) +
                    sumDownFrom(root->right, count);
    ++count[sum];
    return sum;
  }
};
