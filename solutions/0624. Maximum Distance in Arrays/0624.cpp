class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int ans = 0;
    int min = 10000;
    int max = -10000;

    for (const auto& A : arrays) {
      ans = std::max({ans, A.back() - min, max - A.front()});
      min = std::min(min, A.front());
      max = std::max(max, A.back());
    }

    return ans;
  }
};
