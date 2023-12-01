class Solution:
  def maxJump(self, stones: List[int]) -> int:
    # Let's denote the forwarding path as F and the backwarding path as B.
    # 'F1 B2 B1 F2' is no better than 'F1 B2 F2 B1' since the distance between
    # F1 and F2 increase, resulting a larger `ans`.
    if len(stones) == 2:
      return stones[1] - stones[0]
    return max(stones[i] - stones[i - 2]
               for i in range(2, len(stones)))
