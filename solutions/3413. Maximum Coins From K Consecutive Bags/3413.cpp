class Solution {
 public:
  long long maximumCoins(vector<vector<int>>& coins, int k) {
    vector<vector<int>> negatedCoins = negateLeftRight(coins);
    return max(slide(coins, k), slide(negatedCoins, k));
  }

 private:
  vector<vector<int>> negateLeftRight(const vector<vector<int>> coins) {
    vector<vector<int>> res;
    for (const vector<int>& coin : coins) {
      const int l = coin[0];
      const int r = coin[1];
      const int c = coin[2];
      res.push_back({-r, -l, c});
    }
    return res;
  }

  long slide(vector<vector<int>>& coins, int k) {
    long res = 0;
    long windowSum = 0;
    int j = 0;

    ranges::sort(coins);

    for (const vector<int>& coin : coins) {
      const int li = coin[0];
      const int ri = coin[1];
      const int ci = coin[2];
      const int rightBoundary = li + k;

      // [lj, rj] is fully in [li..li + k)
      while (j + 1 < coins.size() && coins[j + 1][0] < rightBoundary) {
        const int lj = coins[j][0];
        const int rj = coins[j][1];
        const int cj = coins[j][2];
        windowSum += static_cast<long>(rj - lj + 1) * cj;
        ++j;
      }

      // [lj, rj] may be partially in [l..l + k)
      long last = 0;
      if (j < coins.size() && coins[j][0] < rightBoundary) {
        const int lj = coins[j][0];
        const int rj = coins[j][1];
        const int cj = coins[j][2];
        last = static_cast<long>(min(rightBoundary - 1, rj) - lj + 1) * cj;
      }

      res = max(res, windowSum + last);
      windowSum -= static_cast<long>(ri - li + 1) * ci;
    }

    return res;
  }
};
