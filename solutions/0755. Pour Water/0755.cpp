class Solution {
 public:
  vector<int> pourWater(vector<int>& heights, int V, int K) {
    const int n = heights.size();

    int i = K;
    while (V--) {
      while (i > 0 && heights[i] >= heights[i - 1])
        --i;
      while (i + 1 < n && heights[i] >= heights[i + 1])
        ++i;
      while (i > K && heights[i] == heights[i - 1])
        --i;
      ++heights[i];
    }

    return heights;
  }
};
