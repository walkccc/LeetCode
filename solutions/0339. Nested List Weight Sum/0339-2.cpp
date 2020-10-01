class Solution {
 public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int ans = 0;

    addInteger(nestedList, 1, ans);

    return ans;
  }

 private:
  void addInteger(const vector<NestedInteger>& nestedList, int depth, int& ans) {
    for (const NestedInteger& ni : nestedList)
      if (ni.isInteger())
        ans += ni.getInteger() * depth;
      else
        addInteger(ni.getList(), depth + 1, ans);
  }
};