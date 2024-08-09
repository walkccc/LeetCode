class Solution:
  def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
    n = len(maxHeights)
    maxSum = [0] * n  # maxSum[i] := the maximum sum with peak i

    def process(stack: List[int], i: int, summ: int) -> int:
      while len(stack) > 1 and maxHeights[stack[-1]] > maxHeights[i]:
        j = stack.pop()
        # The last abs(j - stack[-1]) heights are maxHeights[j].
        summ -= abs(j - stack[-1]) * maxHeights[j]
      # Put abs(i - stack[-1]) `maxHeight` in heights.
      summ += abs(i - stack[-1]) * maxHeights[i]
      stack.append(i)
      return summ

    stack = [-1]
    summ = 0
    for i in range(len(maxHeights)):
      summ = process(stack, i, summ)
      maxSum[i] = summ

    stack = [n]
    summ = 0
    for i in range(n - 1, -1, -1):
      summ = process(stack, i, summ)
      maxSum[i] += summ - maxHeights[i]

    return max(maxSum)
