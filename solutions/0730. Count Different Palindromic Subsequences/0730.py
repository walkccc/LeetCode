class Solution:
  def countPalindromicSubsequences(self, S: str) -> int:
    def count(l: int, r: int) -> int:
      if l > r:
        return 0
      if l == r:
        return 1
      key = l * len(S) + r
      if key in memo:
        return memo[key]

      if S[l] == S[r]:
        lo = l + 1
        hi = r - 1
        while lo <= hi and S[lo] != S[l]:
          lo += 1
        while lo <= hi and S[hi] != S[l]:
          hi -= 1
        if lo > hi:
          ans = count(l + 1, r - 1) * 2 + 2
        elif lo == hi:
          ans = count(l + 1, r - 1) * 2 + 1
        else:
          ans = count(l + 1, r - 1) * 2 - count(lo + 1, hi - 1)
      else:
        ans = count(l, r - 1) + count(l + 1, r) - count(l + 1, r - 1)

      memo[key] = (ans + kMod) % kMod
      return memo[key]

    kMod = int(1e9 + 7)
    memo = {}

    return count(0, len(S) - 1)
