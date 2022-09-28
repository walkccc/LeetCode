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
  unordered_map<int, bool> memo;  // true: can win, false: can't win

  // state: record integers that have been chosen
  bool dp(int total, int state, int n) {
    if (total <= 0)
      return false;
    if (memo.count(state))
      return memo[state];

    for (int i = 1; i <= n; ++i) {
      if (state & 1 << i)  // integer i is used
        continue;
      if (!dp(total - i, state | 1 << i, n))
        return true;
    }

    return memo[state] = false;
  }
};
