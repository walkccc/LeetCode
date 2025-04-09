class Solution:
  def constrainedSubsetSum(self, nums: list[int], k: int) -> int:
    # dp[i] := the maximum the sum of non-empty subsequences in nums[0..i]
    dp = [0] * len(nums)
    # dq stores dp[i - k], dp[i - k + 1], ..., dp[i - 1] whose values are > 0
    # in decreasing order.
    dq = collections.deque()

    for i, num in enumerate(nums):
      if dq:
        dp[i] = max(dq[0], 0) + num
      else:
        dp[i] = num
      while dq and dq[-1] < dp[i]:
        dq.pop()
      dq.append(dp[i])
      if i >= k and dp[i - k] == dq[0]:
        dq.popleft()

    return max(dp)
