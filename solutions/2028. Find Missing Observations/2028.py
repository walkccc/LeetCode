class Solution:
  def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
    targetSum = (len(rolls) + n) * mean
    missingSum = targetSum - sum(rolls)
    if missingSum > n * 6 or missingSum < n:
      return []

    ans = [missingSum // n] * n
    for i in range(missingSum % n):
      ans[i] += 1

    return ans
