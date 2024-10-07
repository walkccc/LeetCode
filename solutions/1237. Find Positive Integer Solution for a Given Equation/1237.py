class Solution:
  def findSolution(self, customfunction: 'CustomFunction', z: int) -> list[list[int]]:
    ans = []
    x = 1
    y = 1000

    while x <= 1000 and y >= 1:
      f = customfunction.f(x, y)
      if f < z:
        x += 1
      elif f > z:
        y -= 1
      else:
        ans.append([x, y])
        x += 1
        y -= 1

    return ans
