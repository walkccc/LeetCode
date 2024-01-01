class Solution:
  def largestAltitude(self, gain: List[int]) -> int:
    ans = 0
    currAltitude = 0
    for g in gain:
      currAltitude += g
      ans = max(ans, currAltitude)
    return ans
