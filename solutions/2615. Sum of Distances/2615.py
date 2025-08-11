class Solution:
  def distance(self, nums: list[int]) -> list[int]:
    ans = [0] * len(nums)
    numToIndices = collections.defaultdict(list)

    for i, num in enumerate(nums):
      numToIndices[num].append(i)

    for indices in numToIndices.values():
      n = len(indices)
      if n == 1:
        continue
      sumSoFar = sum(indices)
      prevIndex = 0
      for i in range(n):
        sumSoFar += (i - 1) * (indices[i] - prevIndex)
        sumSoFar -= (n - 1 - i) * (indices[i] - prevIndex)
        ans[indices[i]] = sumSoFar
        prevIndex = indices[i]

    return ans
