class Solution {
 public:
  int countWays(vector<vector<int>>& ranges) {
    constexpr int kMod = 1'000'000'007;
    int ans = 1;
    int prevEnd = -1;

    ranges::sort(ranges);

    for (const vector<int>& range : ranges) {
      const int start = range[0];
      const int end = range[1];
      if (start > prevEnd)
        ans = ans * 2 % kMod;
      prevEnd = max(prevEnd, end);
    }

    return ans;
  }
};
