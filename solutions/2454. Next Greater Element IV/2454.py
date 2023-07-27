class Solution:
  def secondGreaterElement(self, nums: List[int]) -> List[int]:
    ans = [-1] * len(nums)
    # decreasing stack that stores indices that met the first greater num.
    prevStack = []
    # decreasing stack that stores indices.
    currStack = []

    for i, num in enumerate(nums):
      # Indices in prevStack meet the second greater num.
      while prevStack and nums[prevStack[-1]] < num:
        ans[prevStack.pop()] = num
      # Push indices that meet the first greater num from `currStack` to
      # `prevStack`. We need a temp array to make indices in `prevStack`
      # increasing.
      decreasingIndices = []
      while currStack and nums[currStack[-1]] < num:
        decreasingIndices.append(currStack.pop())
      while decreasingIndices:
        prevStack.append(decreasingIndices.pop())
      currStack.append(i)

    return ans
