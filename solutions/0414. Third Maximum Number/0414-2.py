class Solution:
  def thirdMax(self, nums: List[int]) -> int:
    pq = []
    seen = set()

    for num in nums:
      if num not in seen:
        seen.add(num)
        heapq.heappush(pq, num)
        if len(pq) > 3:
          heapq.heappop(pq)

    if len(pq) == 2:
      heapq.heappop(pq)

    return pq[0]
