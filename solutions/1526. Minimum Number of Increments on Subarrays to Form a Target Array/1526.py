class Solution:
  def minNumberOperations(self, target: List[int]) -> int:
    ans = target[0]

    for a, b in zip(target, target[1:]):
      if a < b:
        ans += b - a

    return ans
