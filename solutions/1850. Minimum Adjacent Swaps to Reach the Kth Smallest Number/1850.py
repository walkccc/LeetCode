class Solution:
  def getMinSwaps(self, num: str, k: int) -> int:
    def nextPermutation(nums: List[int]):
      n = len(nums)

      # From the back to the front, find the first num < nums[i + 1].
      i = n - 2
      while i >= 0:
        if nums[i] < nums[i + 1]:
          break
        i -= 1

      # From the back to the front, find the first num > nums[i] and swap it with nums[i].
      if i >= 0:
        for j in range(n - 1, i, -1):
          if nums[j] > nums[i]:
            nums[i], nums[j] = nums[j], nums[i]
            break

      def reverse(nums, l, r):
        while l < r:
          nums[l], nums[r] = nums[r], nums[l]
          l += 1
          r -= 1

      # Reverse nums[i + 1..n - 1]
      reverse(nums, i + 1, len(nums) - 1)

    A = [int(c) for c in num]  # Original
    B = A.copy()  # Permutated

    for _ in range(k):
      nextPermutation(B)

    def countSteps(A: List[int], B: List[int]) -> int:
      count = 0

      j = 0
      for i in range(len(A)):
        j = i
        while A[i] != B[j]:
          j += 1
        while i < j:
          B[j], B[j - 1] = B[j - 1], B[j]
          j -= 1
          count += 1

      return count

    return countSteps(A, B)
