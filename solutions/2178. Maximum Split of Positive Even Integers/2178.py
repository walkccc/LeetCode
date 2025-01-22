class Solution:
  def maximumEvenSplit(self, finalSum: int) -> list[int]:
    if finalSum % 2 == 1:
      return []

    ans = []
    needSum = finalSum
    even = 2

    while needSum - even >= even + 2:
      ans.append(even)
      needSum -= even
      even += 2

    return ans + [needSum]
