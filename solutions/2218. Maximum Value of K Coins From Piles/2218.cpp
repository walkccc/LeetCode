class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    vector<vector<int>> mem(piles.size(), vector<int>(k + 1));
    return maxValueOfCoins(piles, 0, k, mem);
  }

 private:
  // Returns the maximum value of picking k coins from piles[i..n)
  int maxValueOfCoins(const vector<vector<int>>& piles, int i, size_t k,
                      vector<vector<int>>& mem) {
    if (i == piles.size() || k == 0)
      return 0;
    if (mem[i][k])
      return mem[i][k];

    // Pick no coins from the current pile.
    int res = maxValueOfCoins(piles, i + 1, k, mem);
    int val = 0;  // the coins picked from the current pile

    // Try to pick 1, 2, ..., k coins from the current pile.
    for (int j = 0; j < min(piles[i].size(), k); ++j) {
      val += piles[i][j];
      res = max(res, val + maxValueOfCoins(piles, i + 1, k - j - 1, mem));
    }

    return mem[i][k] = res;
  }
};
