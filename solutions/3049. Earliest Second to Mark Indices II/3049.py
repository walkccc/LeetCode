class Solution:
  def earliestSecondToMarkIndices(
      self,
      nums: list[int],
      changeIndices: list[int],
  ) -> int:
    # {the second: the index of nums can be zeroed at the current second}
    secondToIndex = self._getSecondToIndex(nums, changeIndices)
    numsSum = sum(nums)

    def canMark(maxSecond: int) -> bool:
      """
      Returns True if all indices of `nums` can be marked within `maxSecond`.
      """
      # Use a min-heap to greedily pop out the minimum number, which yields the
      # least saving.
      minHeap = []
      marks = 0

      for second in range(maxSecond - 1, -1, -1):
        if second in secondToIndex:
          # The number mapped by the index is a candidate to be zeroed out.
          index = secondToIndex[second]
          heapq.heappush(minHeap, nums[index])
          if marks == 0:
            # Running out of marks, so need to pop out the minimum number.
            # So, the current second will be used to mark an index.
            heapq.heappop(minHeap)
            marks += 1
          else:
            # There're enough marks.
            # So, the current second will be used to zero out a number.
            marks -= 1
        else:
          # There's no candidate to be zeroed out.
          # So, the current second will be used to mark an index.
          marks += 1

      decrementAndMarkCost = ((numsSum - sum(minHeap)) +
                              (len(nums) - len(minHeap)))
      zeroAndMarkCost = len(minHeap) + len(minHeap)
      return decrementAndMarkCost + zeroAndMarkCost <= maxSecond

    l = bisect.bisect_left(range(1, len(changeIndices) + 1), True,
                           key=lambda m: canMark(m)) + 1
    return l if l <= len(changeIndices) else -1

  def _getSecondToIndex(
      self,
      nums: list[int],
      changeIndices: list[int],
  ) -> dict[int, int]:
    # {the `index` of nums: the earliest second to zero out nums[index]}
    indexToFirstSecond = {}
    for zeroIndexedSecond, oneIndexedIndex in enumerate(changeIndices):
      index = oneIndexedIndex - 1  # Convert to 0-indexed.
      if nums[index] > 0 and index not in indexToFirstSecond:
        indexToFirstSecond[index] = zeroIndexedSecond
    return {second: index for index, second in indexToFirstSecond.items()}
