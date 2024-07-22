class Solution {
 public:
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0)
      return {};
    if (n == 1)
      return {new TreeNode(0)};
    if (const auto it = mem.find(n); it != mem.cend())
      return it->second;

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

    return mem[n] = ans;
  }

 private:
  unordered_map<int, vector<TreeNode*>> mem;
};
