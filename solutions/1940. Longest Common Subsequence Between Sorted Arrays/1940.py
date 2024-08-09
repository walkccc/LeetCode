class Solution:
  def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
    kMax = 100
    ans = []
    count = [0] * (kMax + 1)

    for array in arrays:
      for a in array:
        count[a] += 1
        if count[a] == len(arrays):
          ans.append(a)

    return ans
