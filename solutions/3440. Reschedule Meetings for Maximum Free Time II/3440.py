class Solution:
  def maxFreeTime(
      self,
      eventTime: int,
      startTime: list[int],
      endTime: list[int]
  ) -> int:
    n = len(startTime)
    gaps = ([startTime[0]] +
            [startTime[i] - endTime[i - 1] for i in range(1, len(startTime))] +
            [eventTime - endTime[-1]])
    ans = 0
    maxLeft = [gaps[0]] + [0] * n  # maxLeft[i] := max(gaps[0..i])
    maxRight = [0] * n + [gaps[n]]  # maxRight[i] := max(gaps[i..n])

    for i in range(1, n + 1):
      maxLeft[i] = max(gaps[i], maxLeft[i - 1])

    for i in range(n - 1, -1, -1):
      maxRight[i] = max(gaps[i], maxRight[i + 1])

    for i, (start, end) in enumerate(zip(startTime, endTime)):
      currMeetingTime = end - start
      adjacentGapsSum = gaps[i] + gaps[i + 1]
      canMoveMeeting = currMeetingTime <= max(
          maxLeft[i - 1] if i > 0 else 0,
          maxRight[i + 2] if i + 2 < n + 1 else 0
      )
      ans = max(ans, adjacentGapsSum +
                (currMeetingTime if canMoveMeeting else 0))

    return ans
