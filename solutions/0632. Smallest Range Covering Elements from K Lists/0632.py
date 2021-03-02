class Solution:
  def smallestRange(self, nums: List[List[int]]) -> List[int]:
    pq = [(row[0], i, 0) for i, row in enumerate(nums)]
    heapq.heapify(pq)

    maxRange = max(row[0] for row in nums)
    minRange = heapq.nsmallest(1, pq)[0][0]
    ans = [minRange, maxRange]

    while len(pq) == len(nums):
      num, r, c = heapq.heappop(pq)
      if c + 1 < len(nums[r]):
        heapq.heappush(pq, (nums[r][c + 1], r, c + 1))
        maxRange = max(maxRange, nums[r][c + 1])
        minRange = heapq.nsmallest(1, pq)[0][0]
        if maxRange - minRange < ans[1] - ans[0]:
          ans[0], ans[1] = minRange, maxRange

    return ans
