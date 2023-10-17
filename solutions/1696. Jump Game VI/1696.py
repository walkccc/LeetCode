class Solution:
  def maxResult(self, nums: List[int], k: int) -> int:
    # max queue storing dp[i] within the bounds
    dq = collections.deque([0])
    # dp[i] := max score to consider nums[0..i]
    dp = [0] * len(nums)
    dp[0] = nums[0]

    for i in range(1, len(nums)):
      # Pop the index if it's out of bounds.
      if dq[0] + k < i:
        dq.popleft()
      dp[i] = dp[dq[0]] + nums[i]
      # Pop indices that won't be chosen in the future.
      while dq and dp[dq[-1]] <= dp[i]:
        dq.pop()
      dq.append(i)

    return dp[-1]
