class Solution:
  def minMeetingRooms(self, intervals: list[list[int]]) -> int:
    n = len(intervals)
    ans = 0
    starts = []
    ends = []

    for start, end in intervals:
      starts.append(start)
      ends.append(end)

    starts.sort()
    ends.sort()

    j = 0
    for i in range(n):
      if starts[i] < ends[j]:
        ans += 1
      else:
        j += 1

    return ans
