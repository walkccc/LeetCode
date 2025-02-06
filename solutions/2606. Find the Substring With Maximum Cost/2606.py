class Solution:
  def maximumCostSubstring(self, s: str, chars: str, vals: list[int]) -> int:
    ans = 0
    cost = 0
    costs = [i for i in range(1, 27)]  # costs[i] := the cost of 'a' + i

    for c, val in zip(chars, vals):
      costs[string.ascii_lowercase.index(c)] = val

    for c in s:
      cost = max(0, cost + costs[string.ascii_lowercase.index(c)])
      ans = max(ans, cost)

    return ans
