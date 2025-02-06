class Solution:
  def minimumXORSum(self, nums1: list[int], nums2: list[int]) -> int:
    @functools.lru_cache(None)
    def dp(mask: int) -> int:
      i = mask.bit_count()
      if i == len(nums1):
        return 0
      return min((nums1[i] ^ nums2[j]) + dp(mask | 1 << j)
                 for j in range(len(nums2)) if not mask >> j & 1)
    return dp(0)
