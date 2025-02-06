class Solution:
  def countNonDecreasingSubarrays(self, nums: list[int], k: int) -> int:
    ans = 0
    cost = 0
    # Store indices (i) of nums with nums[i] in non-increasing order.
    dq = collections.deque()

    j = len(nums) - 1
    for i, num in reversed(list(enumerate(nums))):
      while dq and nums[dq[-1]] < num:
        l = dq.pop()
        r = dq[-1] if dq else j + 1
        cost += (r - l) * (num - nums[l])  # Adjust `nums[l]` to `num`.
      dq.append(i)
      while cost > k:  # Remove the rightmost number.
        cost -= nums[dq[0]] - nums[j]
        if dq[0] == j:
          dq.popleft()
        j -= 1
      ans += j - i + 1

    return ans
