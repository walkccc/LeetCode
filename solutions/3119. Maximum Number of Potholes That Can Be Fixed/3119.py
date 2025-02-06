class Solution:
  def maxPotholes(self, road: str, budget: int) -> int:
    ans = 0

    for length in sorted(map(len, road.split('.')), reverse=True):
      canRepair = max(0, budget - 1)
      if length > canRepair:
        return ans + canRepair
      ans += length
      budget -= length + 1

    return ans
