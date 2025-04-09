class Solution {
 public:
  int subsequencesWithMiddleMode(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> p;  // prefix counter
    unordered_map<int, int> s;  // suffix counter

    for (const int num : nums)
      ++s[num];

    for (int i = 0; i < nums.size(); ++i) {
      const int a = nums[i];
      --s[a];

      const int l = i;
      const int r = nums.size() - i - 1;

      // Start with all possible subsequences with `a` as the middle number.
      ans = (ans + nC2(l) * nC2(r)) % kMod;

      // Minus cases where frequency of `a` is 1, so it's not a mode.
      ans = (ans - nC2(l - p[a]) * nC2(r - s[a])) % kMod;

      for (const int b : getUniqueNums(p, s)) {
        if (b == a)
          continue;

        // Minus cases where the middle number is not a "unique" mode
        int subtract = 0;

        // [a b] a [b c]
        subtract = (subtract + p[a] * p[b] * s[b] * (r - s[a] - s[b])) % kMod;

        // [b c] a [a b]
        subtract = (subtract + s[a] * s[b] * p[b] * (l - p[a] - p[b])) % kMod;

        // [b b] a [a c]
        subtract = (subtract + nC2(p[b]) * s[a] * (r - s[a] - s[b])) % kMod;

        // [a c] a [b b]
        subtract = (subtract + nC2(s[b]) * p[a] * (l - p[a] - p[b])) % kMod;

        // [b b] a [a b]
        subtract = (subtract + nC2(p[b]) * s[a] * s[b]) % kMod;

        // [a b] a [b b]
        subtract = (subtract + nC2(s[b]) * p[a] * p[b]) % kMod;

        ans = (ans - subtract + kMod) % kMod;
      }

      ++p[a];
    }

    return (ans + kMod) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns C(n, 2).
  long nC2(long n) {
    return n * (n - 1) / 2 % kMod;
  }

  unordered_set<int> getUniqueNums(const unordered_map<int, int>& p,
                                   const unordered_map<int, int>& s) {
    unordered_set<int> uniqueNums;
    for (const auto& [num, _] : p)
      uniqueNums.insert(num);
    for (const auto& [num, _] : s)
      uniqueNums.insert(num);
    return uniqueNums;
  }
};
