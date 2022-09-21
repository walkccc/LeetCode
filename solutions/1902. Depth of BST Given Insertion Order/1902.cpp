class Solution {
 public:
  int maxDepthBST(vector<int>& order) {
    int ans = 1;
    map<int, int> map;  // {val: depth}
    map[order[0]] = 1;

    for (int i = 1; i < order.size(); ++i) {
      const int val = order[i];
      const auto l = map.upper_bound(val);  // min > val
      const auto r = map.lower_bound(val);  // min >= val
      const int leftDepth = l == cbegin(map) ? 0 : prev(l)->second;
      const int rightDepth = r == cend(map) ? 0 : r->second;
      const int depth = max(leftDepth, rightDepth) + 1;
      ans = max(ans, depth);
      map[val] = depth;
    }

    return ans;
  }
};
