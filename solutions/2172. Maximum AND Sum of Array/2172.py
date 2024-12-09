class Solution:
  def maximumANDSum(self, nums: list[int], numSlots: int) -> int:
    n = 2 * numSlots
    nSelected = 1 << n
    # dp[i] := the maximum value, where i is the bitmask of the selected
    # numbers
    dp = [0] * nSelected

    nums += [0] * (n - len(nums))

    for mask in range(1, nSelected):
      selected = mask.bit_count()
      slot = (selected + 1) // 2  # (1, 2) -> 1, (3, 4) -> 2
      for i, num in enumerate(nums):
        if mask >> i & 1:  # Assign `nums[i]` to the `slot`-th slot.
          dp[mask] = max(dp[mask], dp[mask ^ 1 << i] + (slot & num))

    return dp[-1]
