class Solution:
  def makeStringGood(self, s: str) -> int:
    count = [0] * 26
    for c in s:
      count[ord(c) - ord('a')] += 1
    return min(self._getMinOperations(count, target)
               for target in range(1, max(count) + 1))

  def _getMinOperations(self, count: list[int], target: int) -> int:
    # dp[i] represents the minimum number of operations to make the frequency of
    # (i..25)-th (0-indexed) letters equal to `target`.
    dp = [0] * 27

    for i in range(25, -1, -1):
      # 1. Delete all the i-th letters.
      deleteAllToZero = count[i]
      # 2. Insert/delete the i-th letters to have `target` number of letters.
      deleteOrInsertToTarget = abs(target - count[i])
      dp[i] = min(deleteAllToZero, deleteOrInsertToTarget) + dp[i + 1]
      if i + 1 < 26 and count[i + 1] < target:
        nextDeficit = target - count[i + 1]
        # Make the frequency of the i-th letter equal to the `target` or 0.
        needToChange = count[i] if count[i] <= target else count[i] - target
        changeToTarget = (
            # 3. Change all the i-th letters to the next letter and then
            # insert the remaining deficit for the next letter.
            needToChange + (nextDeficit - needToChange) if nextDeficit > needToChange
            # 4. Change `nextDeficit` i-th letters to the next letter and
            # then delete the remaining i-th letters.
            else nextDeficit + (needToChange - nextDeficit)
        )
        dp[i] = min(dp[i], changeToTarget + dp[i + 2])

    return dp[0]
