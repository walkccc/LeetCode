class Solution:
  def maxResult(self, nums: list[int], k: int) -> int:
    # Stores dp[i] within the bounds.
    maxQ = collections.deque([0])
    # dp[i] := the maximum score to consider nums[0..i]
    dp = [0] * len(nums)
    dp[0] = nums[0]

    for i in range(1, len(nums)):
      # Pop the index if it's out-of-bounds.
      if maxQ[0] + k < i:
        maxQ.popleft()
      dp[i] = dp[maxQ[0]] + nums[i]
      # Pop indices that won't be chosen in the future.
      while maxQ and dp[maxQ[-1]] <= dp[i]:
        maxQ.pop()
      maxQ.append(i)

    return dp[-1]
