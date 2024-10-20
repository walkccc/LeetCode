class Solution:
  def isArmstrong(self, n: int) -> bool:
    s = str(n)
    k = len(s)
    return sum(pow(int(c), k) for c in s) == n
