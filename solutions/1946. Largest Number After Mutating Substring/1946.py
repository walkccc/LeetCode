class Solution:
  def maximumNumber(self, num: str, change: list[int]) -> str:
    numList = list(num)
    mutated = False

    for i, c in enumerate(numList):
      d = int(c)
      numlist[i] = chr(ord('0') + max(d, change[d]))
      if mutated and d > change[d]:
        return ''.join(numList)
      if d < change[d]:
        mutated = True

    return ''.join(numList)
