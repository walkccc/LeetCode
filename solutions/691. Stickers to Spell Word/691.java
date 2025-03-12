class Solution {
  public int minStickers(String[] stickers, String target) {
    final int n = target.length();
    final int maxMask = 1 << n;
    // dp[i] := the minimum number of stickers to spell out i, where i is the
    // bit mask of target
    int[] dp = new int[maxMask];
    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[0] = 0;

    for (int mask = 0; mask < maxMask; ++mask) {
      if (dp[mask] == Integer.MAX_VALUE)
        continue;
      // Try to expand from `mask` by using each sticker.
      for (final String sticker : stickers) {
        int superMask = mask;
        for (final char c : sticker.toCharArray())
          for (int i = 0; i < n; ++i)
            // Try to apply it on a missing letter.
            if (c == target.charAt(i) && (superMask >> i & 1) == 0) {
              superMask |= 1 << i;
              break;
            }
        dp[superMask] = Math.min(dp[superMask], dp[mask] + 1);
      }
    }

    return dp[maxMask - 1] == Integer.MAX_VALUE ? -1 : dp[maxMask - 1];
  }
}
