class Solution:
  def maxFrequencyScore(self, nums: list[int], k: int) -> int:
    MOD = 1_000_000_007
    count = collections.Counter(nums[:k])
    summ = self._getInitialSumm(count, MOD)
    ans = summ

    for i in range(k, len(nums)):
      # Remove the leftmost number that's out-of-window.
      leftNum = nums[i - k]
      summ = (summ - pow(leftNum, count[leftNum], MOD) + MOD) % MOD
      # After decreasing its frequency, if it's still > 0, then add it back.
      count[leftNum] -= 1
      if count[leftNum] > 0:
        summ = (summ + pow(leftNum, count[leftNum], MOD)) % MOD
      # Otherwise, remove it from the count map.
      else:
        del count[leftNum]
      # Add the current number. Similarly, remove the current score like above.
      rightNum = nums[i]
      if count[rightNum] > 0:
        summ = (summ - pow(rightNum, count[rightNum], MOD) + MOD) % MOD
      count[rightNum] += 1
      summ = (summ + pow(rightNum, count[rightNum], MOD)) % MOD
      ans = max(ans, summ)

    return ans

  def _getInitialSumm(self, count: dict[int, int], MOD: int) -> int:
    summ = 0
    for num, freq in count.items():
      summ = (summ + pow(num, freq, MOD)) % MOD
    return summ
