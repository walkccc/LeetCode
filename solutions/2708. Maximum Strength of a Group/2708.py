class Solution:
  def maxStrength(self, nums: list[int]) -> int:
    posProd = 1
    negProd = 1
    maxNeg = -math.inf
    negCount = 0
    hasPos = False
    hasZero = False

    for num in nums:
      if num > 0:
        posProd *= num
        hasPos = True
      elif num < 0:
        negProd *= num
        maxNeg = max(maxNeg, num)
        negCount += 1
      else:  # num == 0
        hasZero = True

    if negCount == 0 and not hasPos:
      return 0
    if negCount % 2 == 0:
      return negProd * posProd
    if negCount >= 3:
      return negProd // maxNeg * posProd
    if hasPos:
      return posProd
    if hasZero:
      return 0
    return maxNeg
