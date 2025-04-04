class Solution:
  def maxIncreasingGroups(self, usageLimits: list[int]) -> int:
    ans = 1  # the next target length
    availableLimits = 0

    for usageLimit in sorted(usageLimits):
      availableLimits += usageLimit
      # Can create groups 1, 2, ..., ans.
      if availableLimits >= ans * (ans + 1) // 2:
        ans += 1

    return ans - 1
