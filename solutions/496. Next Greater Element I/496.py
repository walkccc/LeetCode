class Solution:
  def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
    numToNextGreater = {}
    stack = []  # a decreasing stack

    for num in nums2:
      while stack and stack[-1] < num:
        numToNextGreater[stack.pop()] = num
      stack.append(num)

    return [numToNextGreater.get(num, -1) for num in nums1]
