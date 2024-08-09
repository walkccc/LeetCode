class Solution:
  def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
    count = collections.Counter()
    for nums in nums1, nums2, nums3:
      count.update(set(nums))
    return [i for i, c in count.items() if c >= 2]
