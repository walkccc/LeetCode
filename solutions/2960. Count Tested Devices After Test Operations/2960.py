class Solution:
  def countTestedDevices(self, batteryPercentages: list[int]) -> int:
    ans = 0

    for batteryPercentage in batteryPercentages:
      if batteryPercentage - ans > 0:
        ans += 1

    return ans
