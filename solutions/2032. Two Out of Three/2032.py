class Solution:
  def twoOutOfThree(
      self,
      nums1: list[int],
      nums2: list[int],
      nums3: list[int],
  ) -> list[int]:
    count = collections.Counter()
    for nums in nums1, nums2, nums3:
      count.update(set(nums))
    return [i for i, c in count.items() if c >= 2]
