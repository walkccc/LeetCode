class Solution {
 public:
  int waysToReachStair(int k) {
    // Let's say we have `down` operation 1 and `jump` operation 2.
    // The final stair is 1 + (2^0 + 2^1 + ... + 2^(jump - 1)) - down = k.
    // => 1 + (2^jump - 1) - down = k.
    // => down = 2^jump - k.
    // Since `down` operations cannot be used consecutively, there're jump + 1
    // positions (before and after each `jump`) for  `down`. The maximum jump is
    // 29, as it satisfies the condition down = 2^jump - k <= jump + 1, with k
    // being the maximum value of 10^9.
    constexpr int kMaxJump = 29;
    const vector<vector<int>> comb = getComb(kMaxJump + 1, kMaxJump + 1);
    int ans = 0;

    for (int jump = 0; jump <= kMaxJump; ++jump) {
      const int down = (1 << jump) - k;
      if (down < 0 || down > jump + 1)
        continue;
      ans += comb[jump + 1][down];
    }

    return ans;
  }

 private:
  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  vector<vector<int>> getComb(int n, int k) {
    vector<vector<int>> comb(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; ++i)
      comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    return comb;
  }
};
