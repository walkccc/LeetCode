class Solution:
  def sampleStats(self, count: List[int]) -> List[float]:
    minimum = 0
    maximum = 0
    mean = 0
    leftMedian = 0
    rightMedian = 0
    mode = -1
    numCount = sum(count)
    newNumCount = 0
    maxCount = 0

    for i, c in enumerate(count):
      if c > 0:
        minimum = i
        break

    for i in range(len(count) - 1, -1, -1):
      if count[i] > 0:
        maximum = i
        break

    for i, c in enumerate(count):
      mean += (i * c) / numCount

    for i, c in enumerate(count):
      newNumCount += c
      if newNumCount >= numCount // 2:
        leftMedian = i
        break

    newNumCount = 0

    for i in range(len(count) - 1, -1, -1):
      newNumCount += count[i]
      if newNumCount >= numCount // 2:
        rightMedian = i
        break

    for i, c in enumerate(count):
      if c > maxCount:
        maxCount = c
        mode = i

    return [minimum, maximum, mean, (leftMedian + rightMedian) / 2, mode]
