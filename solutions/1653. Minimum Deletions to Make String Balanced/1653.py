class Solution:
  # Same as 926. Flip String to Monotone Increasing
  def minimumDeletions(self, s: str) -> int:
    dp = 0  # the number of characters to be deleted to make subso far balanced
    countB = 0

    for c in s:
      if c == 'a':
        # 1. Delete 'a'.
        # 2. Keep 'a' and delete the previous 'b's.
        dp = min(dp + 1, countB)
      else:
        countB += 1

    return dp
