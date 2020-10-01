class Solution {
  public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
    if (schedule.size() <= 1)
      return new ArrayList<>();

    List<Interval> ans = new ArrayList<>();
    List<Interval> intervals = new ArrayList<>();

    schedule.forEach(s -> intervals.addAll(s));
    Collections.sort(intervals, (a, b) -> a.start - b.start);

    int currentEnd = intervals.get(0).end;

    for (final Interval interval : intervals)
      if (interval.start > currentEnd) {
        ans.add(new Interval(currentEnd, interval.start));
        currentEnd = interval.end;
      } else {
        currentEnd = Math.max(currentEnd, interval.end);
      }

    return ans;
  }
}