class Solution:
  def maximumSumOfHeights(self, heights: list[int]) -> int:
    n = len(heights)
    maxSum = [0] * n  # maxSum[i] := the maximum sum with peak i

    def process(stack: list[int], i: int, summ: int) -> int:
      while len(stack) > 1 and heights[stack[-1]] > heights[i]:
        j = stack.pop()
        # The last abs(j - stack[-1]) heights are heights[j].
        summ -= abs(j - stack[-1]) * heights[j]
      # Put abs(i - stack[-1]) `maxHeight` in heights.
      summ += abs(i - stack[-1]) * heights[i]
      stack.append(i)
      return summ

    stack = [-1]
    summ = 0
    for i in range(len(heights)):
      summ = process(stack, i, summ)
      maxSum[i] = summ

    stack = [n]
    summ = 0
    for i in range(n - 1, -1, -1):
      summ = process(stack, i, summ)
      maxSum[i] += summ - heights[i]

    return max(maxSum)
