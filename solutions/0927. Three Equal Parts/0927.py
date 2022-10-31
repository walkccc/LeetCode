class Solution:
  def threeEqualParts(self, A: List[int]) -> List[int]:
    ones = sum(a == 1 for a in A)

    if ones == 0:
      return [0, len(A) - 1]
    if ones % 3 != 0:
      return [-1, -1]

    k = ones // 3
    i = 0

    for i in range(len(A)):
      if A[i] == 1:
        first = i
        break

    gapOnes = k

    for j in range(i + 1, len(A)):
      if A[j] == 1:
        gapOnes -= 1
        if gapOnes == 0:
          second = j
          break

    gapOnes = k

    for i in range(j + 1, len(A)):
      if A[i] == 1:
        gapOnes -= 1
        if gapOnes == 0:
          third = i
          break

    while third < len(A) and A[first] == A[second] == A[third]:
      first += 1
      second += 1
      third += 1

    if third == len(A):
      return [first - 1, second]
    return [-1, -1]
