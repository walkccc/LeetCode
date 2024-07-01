class Solution:
  def maximumEvenSplit(self, finalSum: int) -> List[int]:
    if finalSum & 1:
      return []

    ans = []
    needSum = finalSum
    even = 2

    while needSum - even >= even + 2:
      ans.append(even)
      needSum -= even
      even += 2

    return ans + [needSum]
