class Solution {
 public:
  int maxProduct(TreeNode* root) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    vector<int> allSums;
    const long totalSum = treeSum(root, allSums);

    for (const long sum : allSums)
      ans = max(ans, sum * (totalSum - sum));

    return ans % kMod;
  }

 private:
  int treeSum(TreeNode* root, vector<int>& allSums) {
    if (!root)
      return 0;

    const int leftSum = treeSum(root->left, allSums);
    const int rightSum = treeSum(root->right, allSums);
    const int sum = root->val + leftSum + rightSum;
    allSums.push_back(sum);
    return sum;
  }
};
