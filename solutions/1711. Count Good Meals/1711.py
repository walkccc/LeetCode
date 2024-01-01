class Solution:
  def countPairs(self, deliciousness: List[int]) -> int:
    kMod = 10**9 + 7
    kMaxBit = 20 + 1
    ans = 0
    count = collections.Counter()

    for d in deliciousness:
      for i in range(kMaxBit + 1):
        power = 1 << i
        ans += count[power - d]
        ans %= kMod
      count[d] += 1

    return ans
