class Solution:
  def maxTwoEvents(self, events: List[List[int]]) -> int:
    ans = 0
    maxValue = 0
    evts = []  # (time, isStart, value)

    for s, e, v in events:
      evts.append((s, 1, v))
      evts.append((e + 1, 0, v))

    # When two events have the same time, the one is not start will be in the front
    evts.sort()

    for _, isStart, value in evts:
      if isStart:
        ans = max(ans, value + maxValue)
      else:
        maxValue = max(maxValue, value)

    return ans
