class Solution:
  def getMinDistSum(self, positions: list[list[int]]) -> float:
    def distSum(a: float, b: float) -> float:
      return sum(math.sqrt((a - x)**2 + (b - y)**2)
                 for x, y in positions)

    kErr = 1e-6
    currX = 50
    currY = 50
    ans = distSum(currX, currY)
    step = 1

    while step > kErr:
      shouldDecreaseStep = True
      for dx, dy in [(0, step), (0, -step), (step, 0), (-step, 0)]:
        x = currX + dx
        y = currY + dy
        newDistSum = distSum(x, y)
        if newDistSum < ans:
          ans = newDistSum
          currX = x
          currY = y
          shouldDecreaseStep = False
      if shouldDecreaseStep:
        step /= 10

    return ans
