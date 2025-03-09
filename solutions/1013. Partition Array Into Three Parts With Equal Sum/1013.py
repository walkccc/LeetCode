class Solution:
  def canThreePartsEqualSum(self, arr: list[int]) -> bool:
    summ = sum(arr)
    if summ % 3 != 0:
      return False

    average = summ // 3
    partCount = 0
    partSum = 0

    for a in arr:
      partSum += a
      if partSum == average:
        partCount += 1
        partSum = 0

    # edge case: arr = [0, 0, 0, 0] . partCount = 4.
    return partCount >= 3
