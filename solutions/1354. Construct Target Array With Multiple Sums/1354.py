class Solution:
  def isPossible(self, target: list[int]) -> bool:
    if len(target) == 1:
      return target[0] == 1

    summ = sum(target)
    maxHeap = [-num for num in target]
    heapq.heapify(maxHeap)

    while -maxHeap[0] > 1:
      mx = -heapq.heappop(maxHeap)
      restSum = summ - mx
      # Only occurs if n == 2.
      if restSum == 1:
        return True
      updated = mx % restSum
      # updated == 0 (invalid) or didn't change.
      if updated == 0 or updated == mx:
        return False
      heapq.heappush(maxHeap, -updated)
      summ = summ - mx + updated

    return True
