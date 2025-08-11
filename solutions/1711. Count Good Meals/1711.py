class Solution:
  def countPairs(self, deliciousness: list[int]) -> int:
    MOD = 10**9 + 7
    MAX_BIT = 20 + 1
    ans = 0
    count = collections.Counter()

    for d in deliciousness:
      for i in range(MAX_BIT + 1):
        power = 1 << i
        ans += count[power - d]
        ans %= MOD
      count[d] += 1

    return ans
