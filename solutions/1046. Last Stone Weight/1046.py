class Solution:
  def lastStoneWeight(self, stones: list[int]) -> int:
    pq = [-stone for stone in stones]
    heapq.heapify(pq)

    while len(pq) >= 2:
      n1 = -heapq.heappop(pq)
      n2 = -heapq.heappop(pq)
      if n1 != n2:
        heapq.heappush(pq, -(n1 - n2))

    return 0 if not pq else -pq[0]
