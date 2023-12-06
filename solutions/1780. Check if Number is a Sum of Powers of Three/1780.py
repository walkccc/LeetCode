class Solution:
  def checkPowersOfThree(self, n: int) -> bool:
    while n > 1:
      n, r = divmod(n, 3)
      if r == 2:
        return False
    return True
