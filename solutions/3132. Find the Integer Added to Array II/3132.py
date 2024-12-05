class Solution:
  def minimumAddedInteger(self, nums1: list[int], nums2: list[int]) -> int:
    # After removing two elements from nums1, either nums1[0], nums1[1], or
    # nums1[2] will persist. Therefore, the difference between nums1 (with two
    # elements removed) and nums2 is represented by nums2[0] - nums1[i], where
    # 0 <= i <= 2.
    ans = math.inf

    nums1.sort()
    nums2.sort()

    for i in range(3):
      inc = nums2[0] - nums1[i]
      if self._isValidDiff(nums1, nums2, inc):
        ans = min(ans, inc)

    return ans

  def _isValidDiff(self, nums1: list[int], nums2: list[int], inc: int) -> bool:
    """
    Returns True if it's possible to increase nums1 (with two elements removed)
    by `inc` to nums2.
    """
    removed = 0
    i = 0  # nums2's index

    for num in nums1:
      if num + inc == nums2[i]:
        i += 1
        if i == len(nums2):
          break
      else:
        removed += 1

    return removed <= 2
