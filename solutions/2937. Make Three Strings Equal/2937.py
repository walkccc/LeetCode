class Solution:
  def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
    minLength = min(map(len, [s1, s2, s3]))
    i = 0
    while i < minLength and s1[i] == s2[i] and s2[i] == s3[i]:
      i += 1
    return -1 if i == 0 else len(s1) + len(s2) + len(s3) - i * 3
