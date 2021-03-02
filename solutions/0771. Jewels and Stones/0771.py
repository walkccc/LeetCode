class Solution:
  def numJewelsInStones(self, J: str, S: str) -> int:
    jewels = set(J)
    return sum(s in jewels for s in S)
