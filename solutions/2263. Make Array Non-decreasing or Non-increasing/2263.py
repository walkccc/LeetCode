class Solution:
  def convertArray(self, nums: list[int]) -> int:
    def cost(nums: list[int]) -> int:
      ans = 0
      minHeap = []

      # Greedily make `nums` non-increasing.
      for num in nums:
        if minHeap and minHeap[0] < num:
          ans += num - heapq.heappushpop(minHeap, num)
        heapq.heappush(minHeap, num)

      return ans

    return min(cost(nums), cost([-num for num in nums]))
