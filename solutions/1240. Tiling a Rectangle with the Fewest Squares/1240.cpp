class Solution {
 public:
  int tilingRectangle(int n, int m) {
    return tilingRectangle(n, m, 0, vector<int>(m));
  }

 private:
  constexpr static int kBase = 13;
  unordered_map<long, int> dp;

  int tilingRectangle(int n, int m, long hashedHeights, vector<int>&& heights) {
    if (dp.count(hashedHeights))
      return dp[hashedHeights];

    const auto it = min_element(begin(heights), end(heights));
    const int minHeight = *it;
    if (minHeight == n)  // all filled
      return 0;

    int ans = m * n;
    const int start = it - begin(heights);
    // try to put square of different size that doesn't exceed the width/height
    for (int sz = 1; sz <= min(m - start, n - minHeight); ++sz) {
      // heights[start:start + sz] must has the same height
      if (heights[start + sz - 1] != minHeight)
        break;
      // put a square of size `sz` to cover heights[start:start + sz]
      for (int i = start; i < start + sz; ++i)
        heights[i] += sz;
      ans = min(ans, tilingRectangle(n, m, hash(heights), move(heights)));
      for (int i = start; i < start + sz; ++i)
        heights[i] -= sz;
    }

    return dp[hashedHeights] = 1 + ans;
  }

  long hash(const vector<int>& heights) {
    long hashed = 0;
    for (int i = heights.size() - 1; i >= 0; --i)
      hashed = hashed * kBase + heights[i];
    return hashed;
  }
};
