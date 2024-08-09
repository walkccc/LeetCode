class Solution:
  def widestPairOfIndices(self, nums1: List[int], nums2: List[int]) -> int:
    ans = 0
    prefix = 0
    prefixToIndex = {0: -1}

    for i, (num1, num2) in enumerate(zip(nums1, nums2)):
      prefix += num1 - num2
      ans = max(ans, i - prefixToIndex.setdefault(prefix, i))

    return ans
