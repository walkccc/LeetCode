class Solution {
 public:
  int countPairs(vector<vector<int>>& coordinates, int k) {
    int ans = 0;

    for (int x = 0; x <= k; ++x) {
      const int y = k - x;
      unordered_map<pair<int, int>, int, PairHash> count;
      for (const vector<int>& point : coordinates) {
        const int xi = point[0];
        const int yi = point[1];
        if (const auto it = count.find({xi ^ x, yi ^ y}); it != count.cend())
          ans += it->second;
        ++count[{xi, yi}];
      }
    }

    return ans;
  }

 private:
  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};
