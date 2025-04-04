class Solution:
  def solveQueries(self, nums: list[int], queries: list[int]) -> list[int]:
    n = len(nums)
    # minDist[i] := the minimum distance between nums[i], and any other index j
    # in the circular array, where nums[j] == nums[i]
    minDist = [n] * n
    lastSeen = {}

    for i in range(n * 2):
      index = i % n
      num = nums[index]
      if num in lastSeen:
        prevIndex = lastSeen[num] % n
        d = i - prevIndex
        minDist[index] = min(minDist[index], d)
        minDist[prevIndex] = min(minDist[prevIndex], d)
      lastSeen[num] = i

    return [-1 if minDist[query] == n
            else minDist[query]
            for query in queries]
