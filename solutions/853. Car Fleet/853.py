class Solution:
  def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
    ans = 0
    times = [
        float(target - p) / s for p, s in sorted(zip(position, speed),
                                                 reverse=True)]
    maxTime = 0  # the time of the slowest car to reach the target

    for time in times:
      # A car needs more time to reach the target, so it becomes the slowest.
      if time > maxTime:
        maxTime = time
        ans += 1

    return ans
