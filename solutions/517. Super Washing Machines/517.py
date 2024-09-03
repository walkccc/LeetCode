class Solution:
  def findMinMoves(self, machines: list[int]) -> int:
    dresses = sum(machines)

    if dresses % len(machines) != 0:
      return -1

    ans = 0
    average = dresses // len(machines)
    inout = 0

    for dress in machines:
      inout += dress - average
      ans = max(ans, abs(inout), dress - average)

    return ans
