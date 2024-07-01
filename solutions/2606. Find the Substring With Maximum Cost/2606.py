class Solution:
  def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
    ans = 0
    cost = 0
    costs = [i for i in range(1, 27)]  # costs[i] := the cost of 'a' + i

    for c, val in zip(chars, vals):
      costs[ord(c) - ord('a')] = val

    for c in s:
      cost = max(0, cost + costs[ord(c) - ord('a')])
      ans = max(ans, cost)

    return ans
