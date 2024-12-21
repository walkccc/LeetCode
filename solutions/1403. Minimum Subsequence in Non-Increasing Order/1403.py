class Solution:
  def minSubsequence(self, nums: list[int]) -> list[int]:
    ans = []
    maxHeap = [-num for num in nums]
    heapq.heapify(maxHeap)
    half = sum(nums) // 2

    while half >= 0:
      ans.append(-maxHeap[0])
      half += heapq.heappop(maxHeap)

    return ans
