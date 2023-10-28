class Solution:
  def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
    ans = 0
    time = 0

    for p, g in sorted([(p, g) for (p, g) in zip(plantTime, growTime)], key=lambda x: -x[1]):
      time += p
      ans = max(ans, time + g)

    return ans
