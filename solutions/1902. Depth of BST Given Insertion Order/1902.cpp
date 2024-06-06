class Solution {
 public:
  int maxDepthBST(vector<int>& order) {
    int ans = 1;
    map<int, int> valToDepth;

    for (const int val : order) {
      const auto l = valToDepth.upper_bound(val);
      const auto r = valToDepth.lower_bound(val);
      const int leftDepth = l == valToDepth.cbegin() ? 0 : prev(l)->second;
      const int rightDepth = r == valToDepth.cend() ? 0 : r->second;
      const int depth = max(leftDepth, rightDepth) + 1;
      ans = max(ans, depth);
      valToDepth[val] = depth;
    }

    return ans;
  }
};
