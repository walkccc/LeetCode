class Solution:
  def canMeasureWater(
      self,
      jug1Capacity: int,
      jug2Capacity: int,
      targetCapacity: int,
  ) -> bool:
    return (targetCapacity == 0 or
            jug1Capacity + jug2Capacity >= targetCapacity and
            targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0)
