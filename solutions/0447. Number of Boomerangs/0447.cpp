class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans = 0;

    for (const auto& p : points) {
      unordered_map<int, int> distCount;
      for (const auto& q : points) {
        const int dist = getDist(p, q);
        ++distCount[dist];
      }
      for (const auto& [_, freq] : distCount)
        ans += freq * (freq - 1);  // C(freq, 2)
    }

    return ans;
  }

 private:
  int getDist(const vector<int>& p, const vector<int>& q) {
    return pow(p[0] - q[0], 2) + pow(p[1] - q[1], 2);
  }
};
