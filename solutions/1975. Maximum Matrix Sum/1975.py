class Solution:
  def maxMatrixSum(self, matrix: List[List[int]]) -> int:
    absSum = 0
    minAbs = math.inf
    oddNeg = 0  # 0 := even neg, 1 := odd neg

    for row in matrix:
      for num in row:
        absSum += abs(num)
        minAbs = min(minAbs, abs(num))
        if num < 0:
          oddNeg ^= 1

    return absSum - oddNeg * minAbs * 2
