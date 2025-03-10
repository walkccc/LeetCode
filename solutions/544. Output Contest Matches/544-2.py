class Solution:
  def findContestMatch(self, n: int) -> str:
    matches = [str(i + 1) for i in range(n)]

    while n > 1:
      for i in range(n // 2):
        matches[i] = '(' + matches[i] + ',' + matches[n - 1 - i] + ')'
      n //= 2

    return matches[0]
