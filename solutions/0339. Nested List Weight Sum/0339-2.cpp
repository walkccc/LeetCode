class Solution {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int ans = 0;
    dfs(nestedList, 1, ans);
    return ans;
  }

 private:
  void dfs(const vector<NestedInteger>& nestedList, int depth, int& ans) {
    for (const NestedInteger& ni : nestedList)
      if (ni.isInteger())
        ans += ni.getInteger() * depth;
      else
        dfs(ni.getList(), depth + 1, ans);
  }
};
