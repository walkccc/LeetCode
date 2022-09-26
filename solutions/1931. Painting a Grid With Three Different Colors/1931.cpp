class Solution {
 public:
  int colorTheGrid(int m, int n) {
    this->m = m;
    this->n = n;
    return dp(0, 0, 0, 0);
  }

 private:
  constexpr static int kMod = 1'000'000'007;
  int m;
  int n;
  vector<vector<int>> memo = vector<vector<int>>(1000, vector<int>(1024));

  int dp(int r, int c, int prevColMask, int currColMask) {
    if (c == n)
      return 1;
    if (memo[c][prevColMask])
      return memo[c][prevColMask];
    if (r == m)
      return dp(0, c + 1, currColMask, 0);

    int ans = 0;

    // 1 := red, 2 := green, 3 := blue
    for (int color = 1; color <= 3; ++color) {
      if (getColor(prevColMask, r) == color)
        continue;
      if (r > 0 && getColor(currColMask, r - 1) == color)
        continue;
      ans += dp(r + 1, c, prevColMask, setColor(currColMask, r, color));
      ans %= kMod;
    }

    if (r == 0)
      memo[c][prevColMask] = ans;

    return ans;
  }

  // e.g. __ __ __ __ __
  //      01 10 11 11 11
  //      R  G  B  B  B
  // getColor(0110111111, 3) -> G
  int getColor(int mask, int r) {
    return mask >> r * 2 & 3;
  }

  int setColor(int mask, int r, int color) {
    return mask | color << r * 2;
  }
};
