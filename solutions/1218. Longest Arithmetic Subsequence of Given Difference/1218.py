class Solution:
  def longestSubsequence(self, arr: List[int], difference: int) -> int:
    ans = 0
    lengthAt = {}

    for a in arr:
      lengthAt[a] = lengthAt.get(a - difference, 0) + 1
      ans = max(ans, lengthAt[a])

    return ans
