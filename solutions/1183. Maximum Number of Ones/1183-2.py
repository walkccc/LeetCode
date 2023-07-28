class Solution:
  def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
    subCount = []

    def getCount(length: int, index: int) -> int:
      return (length - index - 1) // sideLength + 1

    for i in range(sideLength):
      for j in range(sideLength):
        subCount.append(getCount(width, i) * getCount(height, j))

    return sum(sorted(subCount, reverse=True)[:maxOnes])
