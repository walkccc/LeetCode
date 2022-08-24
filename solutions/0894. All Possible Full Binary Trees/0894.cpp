class Solution {
 public:
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0)
      return {};
    if (n == 1)
      return {new TreeNode(0)};
    if (memo.count(n))
      return memo[n];

    vector<TreeNode*> ans;

    for (int leftCount = 0; leftCount < n; ++leftCount) {
      const int rightCount = n - 1 - leftCount;
      for (TreeNode* left : allPossibleFBT(leftCount))
        for (TreeNode* right : allPossibleFBT(rightCount)) {
          ans.push_back(new TreeNode(0));
          ans.back()->left = left;
          ans.back()->right = right;
        }
    }

    return memo[n] = ans;
  }

 private:
  unordered_map<int, vector<TreeNode*>> memo;
};
