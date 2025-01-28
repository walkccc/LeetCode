class Solution:
  def earliestSecondToMarkIndices(
      self,
      nums: list[int],
      changeIndices: list[int],
  ) -> int:
    def canMark(second: int) -> bool:
      """
      Returns True if all indices of `nums` can be marked within `second`.
      """
      numMarked = 0
      decrement = 0
      indexToLastSecond = {}

      for i in range(second):
        indexToLastSecond[changeIndices[i] - 1] = i

      for i in range(second):
        index = changeIndices[i] - 1  # Convert to 0-indexed
        if i == indexToLastSecond[index]:
          # Reach the last occurrence of the number.
          # So, the current second will be used to mark the index.
          if nums[index] > decrement:
            # The decrement is less than the number to be marked.
            return False
          decrement -= nums[index]
          numMarked += 1
        else:
          decrement += 1

      return numMarked == len(nums)

    l = 1
    r = len(changeIndices) + 1
    ans = bisect.bisect_left(range(l, r), True, key=canMark) + l
    return ans if ans <= len(changeIndices) else -1
