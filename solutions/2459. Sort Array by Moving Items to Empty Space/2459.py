class Solution:
  def sortArray(self, nums: list[int]) -> int:
    n = len(nums)
    numToIndex = [0] * n

    for i, num in enumerate(nums):
      numToIndex[num] = i

    def minOps(numToIndex: list[int], zeroInBeginning: bool) -> int:
      ops = 0
      num = 1
      # If zeroInBeginning, the correct index of each num is num.
      # If not zeroInBeginning, the correct index of each num is num - 1.
      offset = 0 if zeroInBeginning else 1
      while num < n:
        # 0 is in the correct index, so swap 0 with the first `numInWrongIndex`.
        if (zeroInBeginning and numToIndex[0] == 0 or
                not zeroInBeginning and numToIndex[0] == n - 1):
          while numToIndex[num] == num - offset:  # num is in correct position
            num += 1
            if num == n:
              return ops
          numInWrongIndex = num
        # 0 is in the wrong index. e.g. numToIndex[0] == 2, that means 2 is not
        # in nums[2] because nums[2] == 0.
        else:
          numInWrongIndex = numToIndex[0] + offset
        numToIndex[0], numToIndex[numInWrongIndex] = (
            numToIndex[numInWrongIndex], numToIndex[0])
        ops += 1

    return min(minOps(numToIndex.copy(), True),
               minOps(numToIndex.copy(), False))
