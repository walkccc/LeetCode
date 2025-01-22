class Solution:
  def longestCommonSubsequence(self, arrays: list[list[int]]) -> list[int]:
    kMax = 100
    ans = []
    count = [0] * (kMax + 1)

    for array in arrays:
      for a in array:
        count[a] += 1
        if count[a] == len(arrays):
          ans.append(a)

    return ans
