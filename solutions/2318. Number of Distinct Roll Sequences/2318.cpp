class Solution {
 public:
  int distinctSequences(int n) {
    vector<vector<vector<int>>> mem(n + 1,
                                    vector<vector<int>>(7, vector<int>(7)));
    return distinctSequences(n, 0, 0, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of distinct sequences for n dices with `prev` and
  // `prevPrev`.
  int distinctSequences(int n, int prev, int prevPrev,
                        vector<vector<vector<int>>>& mem) {
    if (n == 0)
      return 1;
    if (mem[n][prev][prevPrev] > 0)
      return mem[n][prev][prevPrev];

    for (int dice = 1; dice <= 6; ++dice)
      if (dice != prev && dice != prevPrev &&
          (prev == 0 || gcd(dice, prev) == 1)) {
        mem[n][prev][prevPrev] += distinctSequences(n - 1, dice, prev, mem);
        mem[n][prev][prevPrev] %= kMod;
      }

    return mem[n][prev][prevPrev];
  }
};
