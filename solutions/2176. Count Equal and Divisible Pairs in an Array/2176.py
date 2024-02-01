class Solution:
  def countPairs(self, nums: List[int], k: int) -> int:
    ans = 0
    numToIndices = collections.defaultdict(list)

    for i, num in enumerate(nums):
      numToIndices[num].append(i)

    for indices in numToIndices.values():
      gcds = collections.Counter()
      for i in indices:
        gcd_i = math.gcd(i, k)
        for gcd_j, count in gcds.items():
          if gcd_i * gcd_j % k == 0:
            ans += count
        gcds[gcd_i] += 1

    return ans
