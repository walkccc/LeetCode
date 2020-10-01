class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0) return true;

    const int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (sum < desiredTotal) return false;

    unordered_map<int, bool> memo;  // true: can win, false: can't win

    // state: record integers that have been chosen
    function<bool(int, int)> dp = [&](int total, int state) {
      if (total <= 0) return false;
      if (memo.count(state)) return memo[state];

      for (int i = 1; i <= maxChoosableInteger; ++i) {
        if (state & (1 << i)) continue;  // integer i is used
        if (!dp(total - i, state | (1 << i))) return true;
      }

      return memo[state] = false;
    };

    return dp(desiredTotal, 0);
  }
};