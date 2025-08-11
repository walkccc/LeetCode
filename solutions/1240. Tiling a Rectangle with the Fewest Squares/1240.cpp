class Solution {
 public:
  int tilingRectangle(int n, int m) {
    unordered_map<long, int> mem;
    return tilingRectangle(n, m, 0, /*heights=*/vector<int>(m), mem);
  }

 private:
  static constexpr int kBase = 13;

  int tilingRectangle(int n, int m, long hashedHeights, vector<int>&& heights,
                      unordered_map<long, int>& mem) {
    if (const auto it = mem.find(hashedHeights); it != mem.cend())
      return it->second;

    const auto it = ranges::min_element(heights);
    const int minHeight = *it;
    if (minHeight == n)  // All filled.
      return 0;

    int ans = m * n;
    const int start = it - heights.begin();
    // Try to put square of different size that doesn't exceed the width/height.
    for (int sz = 1; sz <= min(m - start, n - minHeight); ++sz) {
      // heights[start..start + sz) must has the same height.
      if (heights[start + sz - 1] != minHeight)
        break;
      // Put a square of size `sz` to cover heights[start..start + sz).
      for (int i = start; i < start + sz; ++i)
        heights[i] += sz;
      ans = min(ans,
                tilingRectangle(n, m, hash(heights), std::move(heights), mem));
      for (int i = start; i < start + sz; ++i)
        heights[i] -= sz;
    }

    return mem[hashedHeights] = 1 + ans;
  }

  long hash(const vector<int>& heights) {
    long hashed = 0;
    for (int i = heights.size() - 1; i >= 0; --i)
      hashed = hashed * kBase + heights[i];
    return hashed;
  }
};
