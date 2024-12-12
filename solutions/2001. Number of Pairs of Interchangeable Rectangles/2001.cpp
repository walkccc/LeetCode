class Solution {
 public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    long ans = 0;
    unordered_map<double, int> ratioCount;

    for (const vector<int>& rectangle : rectangles) {
      const int width = rectangle[0];
      const int height = rectangle[1];
      ++ratioCount[1.0 * width / height];
    }

    for (const auto& [_, count] : ratioCount)
      ans += static_cast<long>(count) * (count - 1) / 2;

    return ans;
  }
};
