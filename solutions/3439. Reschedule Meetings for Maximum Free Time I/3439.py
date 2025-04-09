class Solution:
  def maxFreeTime(
      self,
      eventTime: int,
      k: int,
      startTime: list[int],
      endTime: list[int]
  ) -> int:
    gaps = ([startTime[0]] +
            [startTime[i] - endTime[i - 1] for i in range(1, len(startTime))] +
            [eventTime - endTime[-1]])
    windowSum = sum(gaps[:k + 1])
    ans = windowSum

    for i in range(k + 1, len(gaps)):
      windowSum += gaps[i] - gaps[i - k - 1]
      ans = max(ans, windowSum)

    return ans
