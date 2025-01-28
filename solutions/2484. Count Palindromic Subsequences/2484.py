class Solution:
  def countPalindromes(self, s: str) -> int:
    kMod = 1_000_000_007
    ans = 0

    for a in range(10):
      for b in range(10):
        pattern = f'{a}{b}.{b}{a}'
        # dp[i] := the number of subsequences of pattern[i..n) in s, where
        # pattern[2] can be any character
        dp = [0] * 5 + [1]
        for c in s:
          for i, p in enumerate(pattern):
            if p == '.' or p == c:
              dp[i] += dp[i + 1]
        ans += dp[0]
        ans %= kMod

    return ans
