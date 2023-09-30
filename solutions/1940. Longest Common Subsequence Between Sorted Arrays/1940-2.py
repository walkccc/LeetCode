class Solution:
  def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
    return sorted(functools.reduce(lambda a, b: set(a) & set(b), arrays))
