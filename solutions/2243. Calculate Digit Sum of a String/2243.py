class Solution:
  def digitSum(self, s: str, k: int) -> str:
    while len(s) > k:
      next = []
      for i in range(0, len(s), k):
        summ = 0
        for j in range(i, min(len(s), i + k)):
          summ += int(s[j])
        next.append(str(summ))
      s = ''.join(next)
    return s
