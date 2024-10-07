class Solution:
  def countDistinctStrings(self, s: str, k: int) -> int:
    # Since the content of `s` doesn't matter, for each i in [0, n - k], we can
    # flip s[i..i + k] or don't flip it. Therefore, there's 2^(n - k + 1) ways.
    return pow(2, len(s) - k + 1, 1_000_000_007)
