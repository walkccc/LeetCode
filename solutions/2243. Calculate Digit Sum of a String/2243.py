class Solution:
  def digitSum(self, s: str, k: int) -> str:
    while len(s) > k:
      next = []
      for i in range(0, len(s), k):
        sum = 0
        for j in range(i, min(len(s), i + k)):
          sum += ord(s[j]) - ord('0')
        next.append(str(sum))
      s = ''.join(next)
    return s
