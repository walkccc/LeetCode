class Solution:
  def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
    ans = 0

    for boxes, units in sorted(boxTypes, key=lambda x: -x[1]):
      if boxes >= truckSize:
        return ans + truckSize * units
      ans += boxes * units
      truckSize -= boxes

    return ans
