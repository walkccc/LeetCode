class Solution:
  def minimumCost(
      self,
      m: int,
      n: int,
      horizontalCut: list[int],
      verticalCut: list[int],
  ) -> int:
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
