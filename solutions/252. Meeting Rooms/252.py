class Solution:
  def canAttendMeetings(self, intervals: list[list[int]]) -> bool:
    intervals.sort()

    for i in range(1, len(intervals)):
      if intervals[i - 1][1] > intervals[i][0]:
        return False

    return True
