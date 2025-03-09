class Solution:
  def longestCommonSubsequence(self, arrays: list[list[int]]) -> list[int]:
    MAX = 100
    ans = []
    count = [0] * (MAX + 1)

    for array in arrays:
      for a in array:
        count[a] += 1
        if count[a] == len(arrays):
          ans.append(a)

    return ans
