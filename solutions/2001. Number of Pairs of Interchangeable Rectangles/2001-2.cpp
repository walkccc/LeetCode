class Solution {
 public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    long ans = 0;
    unordered_map<pair<int, int>, int, PairHash> ratioCount;

    for (const vector<int>& rectangle : rectangles) {
      const int width = rectangle[0];
      const int height = rectangle[1];
      const int d = __gcd(width, height);
      ++ratioCount[{width / d, height / d}];
    }

    for (const auto& [_, count] : ratioCount)
      ans += static_cast<long>(count) * (count - 1) / 2;

    return ans;
  }

 private:
  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};
