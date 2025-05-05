class Solution:
  def anagramMappings(self, nums1: list[int], nums2: list[int]) -> list[int]:
    numToIndices = collections.defaultdict(list)

    for i, num in enumerate(nums2):
      numToIndices[num].append(i)

    return [numToIndices[num].pop() for num in nums1]
