class Solution:
  def largeGroupPositions(self, s: str) -> list[list[int]]:
    n = len(s)
    ans = []
    i = 0
    j = 0

    while i < n:
      while j < n and s[j] == s[i]:
        j += 1
      if j - i >= 3:
        ans.append([i, j - 1])
      i = j

    return ans
