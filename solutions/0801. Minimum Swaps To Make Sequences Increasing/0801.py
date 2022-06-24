class Solution:
  def minSwap(self, A: List[int], B: List[int]) -> int:
    keepAt = [math.inf] * len(A)
    swapAt = [math.inf] * len(A)
    keepAt[0] = 0
    swapAt[0] = 1

    for i in range(1, len(A)):
      if A[i] > A[i - 1] and B[i] > B[i - 1]:
        keepAt[i] = keepAt[i - 1]
        swapAt[i] = swapAt[i - 1] + 1
      if A[i] > B[i - 1] and B[i] > A[i - 1]:
        keepAt[i] = min(keepAt[i], swapAt[i - 1])
        swapAt[i] = min(swapAt[i], keepAt[i - 1] + 1)

    return min(keepAt[-1], swapAt[-1])
