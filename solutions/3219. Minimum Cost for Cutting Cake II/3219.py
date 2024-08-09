class Solution:
  # Same as 3218. Minimum Cost for Cutting Cake I
  def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
    ans = 0
    sumH = sum(horizontalCut)
    sumV = sum(verticalCut)

    horizontalCut.sort()
    verticalCut.sort()

    while horizontalCut and verticalCut:
      if horizontalCut[-1] > verticalCut[-1]:
        ans += horizontalCut[-1] + sumV
        sumH -= horizontalCut.pop()
      else:
        ans += verticalCut[-1] + sumH
        sumV -= verticalCut.pop()

    return ans + sumH + sumV
