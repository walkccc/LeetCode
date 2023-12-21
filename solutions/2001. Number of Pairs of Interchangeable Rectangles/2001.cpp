class Solution {
 public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    long long ans = 0;
    unordered_map<double, int> ratioCount;

    for (const vector<int>& r : rectangles)
      ++ratioCount[(double)r[0] / r[1]];

    for (const auto& [_, count] : ratioCount)
      ans += static_cast<long>(count) * (count - 1) / 2;

    return ans;
  }
};
