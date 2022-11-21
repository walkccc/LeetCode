class Solution:
  def subarrayGCD(self, nums: List[int], k: int) -> int:
    ans = 0
    gcds = Counter()

    for num in nums:
      if num % k == 0:
        nextGcds = defaultdict(int)
        nextGcds[num] += 1
        for prevGcd, count in gcds.items():
          nextGcds[math.gcd(prevGcd, num)] += count
        ans += nextGcds.get(k, 0)
        gcds = nextGcds
      else:
        # The GCD streak stops, so fresh start from the next num.
        gcds.clear()

    return ans
