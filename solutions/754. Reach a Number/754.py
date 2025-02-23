class Solution:
  def reachNumber(self, target: int) -> int:
    ans = 0
    pos = 0
    target = abs(target)

    while pos < target:
      ans += 1
      pos += ans

    while (pos - target) % 2 == 1:
      ans += 1
      pos += ans

    return ans
