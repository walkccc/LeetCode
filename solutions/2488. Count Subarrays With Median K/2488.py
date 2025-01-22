class Solution:
  def countSubarrays(self, nums: list[int], k: int) -> int:
    kIndex = nums.index(k)
    ans = 0
    count = collections.Counter()

    balance = 0
    for i in range(kIndex, -1, -1):
      if nums[i] < k:
        balance -= 1
      elif nums[i] > k:
        balance += 1
      count[balance] += 1

    balance = 0
    for i in range(kIndex, len(nums)):
      if nums[i] < k:
        balance -= 1
      elif nums[i] > k:
        balance += 1
      # The subarray that has balance == 0 or 1 having median equal to k.
      # So, add count[0 - balance] and count[1 - balance] to `ans`.
      ans += count[-balance] + count[1 - balance]

    return ans
