class Solution:
  def longestCommonSubsequence(self, arrays: list[list[int]]) -> list[int]:
    return sorted(functools.reduce(lambda a, b: set(a) & set(b), arrays))
