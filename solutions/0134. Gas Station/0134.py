class Solution:
  def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
    ans = 0
    net = 0
    sum = 0

    for i in range(len(gas)):
      net += gas[i] - cost[i]
      sum += gas[i] - cost[i]
      if sum < 0:
        sum = 0
        ans = i + 1

    return -1 if net < 0 else ans
