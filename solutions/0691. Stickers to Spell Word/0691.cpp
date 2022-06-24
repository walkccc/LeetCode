class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    const int n = target.size();
    const int maxMask = 1 << n;
    // dp[i] := min # of stickers to spell out i,
    // where i is the bit representation of target
    vector<int> dp(maxMask, INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < maxMask; ++mask) {
      if (dp[mask] == INT_MAX)
        continue;
      // try to expand from `mask` by using each sticker
      for (const auto& sticker : stickers) {
        int superMask = mask;
        for (const char c : sticker)
          for (int i = 0; i < n; ++i)
            // try to apply it on a missing char
            if (c == target[i] && !(superMask >> i & 1)) {
              superMask |= 1 << i;
              break;
            }
        dp[superMask] = min(dp[superMask], dp[mask] + 1);
      }
    }

    return dp.back() == INT_MAX ? -1 : dp.back();
  }
};
