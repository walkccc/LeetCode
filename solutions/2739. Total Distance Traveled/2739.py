class Solution:
  def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
    # M  M M M M  A  M M M M   A
    # 1 [2 3 4 5] 6 [7 8 9 10] 11
    return (mainTank + min((mainTank - 1) // 4, additionalTank)) * 10
