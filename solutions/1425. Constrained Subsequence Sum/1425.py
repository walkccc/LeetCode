class Solution:
  def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
    # dp[i] := max sum of non-empty subsequence in nums[0..i]
    dp = [0] * len(nums)
    # q stores dp[i - k], dp[i - k + 1], ..., dp[i - 1] whose values are > 0 in decreasing order
    q = deque()

    for i, num in enumerate(nums):
      if q:
        dp[i] = max(q[0], 0) + num
      else:
        dp[i] = num
      while q and q[-1] < dp[i]:
        q.pop()
      q.append(dp[i])
      if i >= k and dp[i - k] == q[0]:
        q.popleft()

    return max(dp)
