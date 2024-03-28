class Solution:
  def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
    numToIndices = collections.defaultdict(list)

    for i, num in enumerate(nums2):
      numToIndices[num].append(i)

    return [numToIndices[num].pop() for num in nums1]
