class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0)
      return true;

    const int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (sum < desiredTotal)
      return false;

    return dp(desiredTotal, 0, maxChoosableInteger);
  }

 private:
  unordered_map<int, bool> memo;  // true := can win, false := can't win

  bool dp(int total, int bitmask, int n) {
    if (total <= 0)
      return false;
    if (const auto it = memo.find(bitmask); it != memo.cend())
      return it->second;

    for (int i = 1; i <= n; ++i) {
      if (bitmask & 1 << i)  // Integer i is used.
        continue;
      if (!dp(total - i, bitmask | 1 << i, n))
        return true;
    }

    return memo[bitmask] = false;
  }
};
