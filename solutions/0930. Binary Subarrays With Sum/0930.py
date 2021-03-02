class Solution:
  def numSubarraysWithSum(self, A: List[int], S: int) -> int:
    ans = 0
    prefix = 0
    count = Counter({0: 1})

    for a in A:
      prefix += a
      ans += count[prefix - S]
      count[prefix] += 1

    return ans
