class Solution:
  def maxFrequencyScore(self, nums: List[int], k: int) -> int:
    kMod = 1_000_000_007
    count = collections.Counter(nums[:k])
    summ = self._getInitialSumm(count, kMod)
    ans = summ

    for i in range(k, len(nums)):
      # Remove the leftmost number that's out-of-window.
      leftNum = nums[i - k]
      summ = (summ - pow(leftNum, count[leftNum], kMod) + kMod) % kMod
      # After decreasing its frequency, if it's still > 0, then add it back.
      count[leftNum] -= 1
      if count[leftNum] > 0:
        summ = (summ + pow(leftNum, count[leftNum], kMod)) % kMod
      # Otherwise, remove it from the count map.
      else:
        del count[leftNum]
      # Add the current number. Similarly, remove the current score like above.
      rightNum = nums[i]
      if count[rightNum] > 0:
        summ = (summ - pow(rightNum, count[rightNum], kMod) + kMod) % kMod
      count[rightNum] += 1
      summ = (summ + pow(rightNum, count[rightNum], kMod)) % kMod
      ans = max(ans, summ)

    return ans

  def _getInitialSumm(self, count: Dict[int, int], kMod: int) -> int:
    summ = 0
    for num, freq in count.items():
      summ = (summ + pow(num, freq, kMod)) % kMod
    return summ
