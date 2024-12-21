class Solution:
  def unmarkedSumArray(
      self,
      nums: list[int],
      queries: list[list[int]],
  ) -> list[int]:
    ans = []
    marked = set()
    summ = sum(nums)
    minHeap = [(num, i) for i, num in enumerate(nums)]
    heapq.heapify(minHeap)

    for index, k in queries:
      if index not in marked:
        marked.add(index)
        summ -= nums[index]
      popped = 0
      while popped < k and minHeap:
        num, i = heapq.heappop(minHeap)
        if i not in marked:
          marked.add(i)
          summ -= num
          popped += 1
      ans.append(summ)

    return ans
