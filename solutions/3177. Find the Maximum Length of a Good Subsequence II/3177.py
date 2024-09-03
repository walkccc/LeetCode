class Solution:
  # Same as 3176. Find the Maximum Length of a Good Subsequence I
  def maximumLength(self, nums: list[int], k: int) -> int:
    # dp[count][num] := the maximum length of a good subsequence with at most
    # `count` indices where seq[i] != seq[i + 1] and it ends in `num`.
    dp = [collections.Counter() for _ in range(k + 1)]
    # maxLen[count] := the maximum length of a good subsequence with `count`
    # indices where seq[i] != seq[i + 1]
    maxLen = [0] * (k + 1)

    for num in nums:
      for count in range(k, -1, -1):
        # Append `num` to the subsequence.
        dp[count][num] += 1
        if count > 0:
          dp[count][num] = max(dp[count][num], maxLen[count - 1] + 1)
        maxLen[count] = max(maxLen[count], dp[count][num])

    return maxLen[k]
