class Solution:
  def meetRequirement(self, n: int, lights: List[List[int]], requirement: List[int]) -> int:
    ans = 0
    currBrightness = 0
    change = [0] * (n + 1)

    for position, rg in lights:
      change[max(0, position - rg)] += 1
      change[min(n, position + rg + 1)] -= 1

    for i in range(n):
      currBrightness += change[i]
      if currBrightness >= requirement[i]:
        ans += 1

    return ans
