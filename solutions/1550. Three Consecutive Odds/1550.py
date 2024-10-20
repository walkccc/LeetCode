class Solution:
  def threeConsecutiveOdds(self, arr: list[int]) -> bool:
    count = 0
    for a in arr:
      count = 0 if a % 2 == 0 else count + 1
      if count == 3:
        return True
    return False
