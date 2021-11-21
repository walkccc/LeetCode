class Solution:
  def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
    if len(schedule) <= 1:
      return []

    ans = []
    intervals = []

    for workingTimes in schedule:
      for interval in workingTimes:
        intervals.append(interval)

    intervals.sort(key=lambda x: x.start)

    prevEnd = intervals[0].end

    for interval in intervals:
      if interval.start > prevEnd:
        ans.append(Interval(prevEnd, interval.start))
      prevEnd = max(prevEnd, interval.end)

    return ans
