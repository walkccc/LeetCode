class Solution:
  def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
    minHeap = list(collections.Counter(arr).values())
    heapq.heapify(minHeap)

    # Greedily remove k least frequent nums to have least # of unique integers.
    while k > 0:
      k -= heapq.heappop(minHeap)

    return len(minHeap) + (1 if k < 0 else 0)
