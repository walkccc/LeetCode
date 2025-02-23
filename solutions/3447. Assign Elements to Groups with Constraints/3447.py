class Solution:
  def assignElements(self, groups: list[int], elements: list[int]) -> list[int]:
    ans = []
    elementToMinIndex = {}

    for i, element in enumerate(elements):
      if element not in elementToMinIndex:
        elementToMinIndex[element] = i

    for num in groups:
      ans.append(self._getMinIndex(num, elementToMinIndex))

    return ans

  def _getMinIndex(self, num: int, elementToMinIndex: dict[int, int]) -> int:
    res = math.inf
    i = 1
    while i * i <= num:
      if num % i != 0:
        continue
      if i in elementToMinIndex:
        res = min(res, elementToMinIndex[i])
      if num // i != i and (num // i) in elementToMinIndex:
        res = min(res, elementToMinIndex[num // i])
      i += 1
    return -1 if res == math.inf else res
