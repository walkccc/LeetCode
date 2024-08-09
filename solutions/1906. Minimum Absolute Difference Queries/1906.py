class Solution:
  def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
    numToIndices = [[] for _ in range(101)]

    for i, num in enumerate(nums):
      numToIndices[num].append(i)

    if len(numToIndices[nums[0]]) == len(nums):
      return [-1] * len(queries)

    ans = []

    for l, r in queries:
      prevNum = -1
      minDiff = 101
      for num in range(1, 101):
        indices = numToIndices[num]
        i = bisect_left(indices, l)
        if i == len(indices) or indices[i] > r:
          continue
        if prevNum != -1:
          minDiff = min(minDiff, num - prevNum)
        prevNum = num
      ans.append(-1 if minDiff == 101 else minDiff)

    return ans
