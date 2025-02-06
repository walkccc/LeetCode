class Solution:
  def countPairs(self, nums: list[int], k: int) -> int:
    ans = 0
    gcds = collections.Counter()

    for num in nums:
      gcd_i = math.gcd(num, k)
      for gcd_j, count in gcds.items():
        if gcd_i * gcd_j % k == 0:
          ans += count
      gcds[gcd_i] += 1

    return ans
