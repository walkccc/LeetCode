class Solution:
  def canThreePartsEqualSum(self, A: List[int]) -> bool:
    summ = sum(A)
    prefix = 0
    parts = 1

    for a in A:
      prefix += a
      if prefix == summ * parts // 3:
        parts += 1

    return summ % 3 == 0 and parts >= 3
