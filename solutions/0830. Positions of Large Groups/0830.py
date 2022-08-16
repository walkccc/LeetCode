class Solution:
  def largeGroupPositions(self, S: str) -> List[List[int]]:
    n = len(S)
    ans = []
    i = 0
    j = 0

    while i < n:
      while j < n and S[j] == S[i]:
        j += 1
      if j - i >= 3:
        ans.append([i, j - 1])
      i = j

    return ans
