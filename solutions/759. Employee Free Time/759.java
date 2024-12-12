class Solution {
  public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
    List<Interval> ans = new ArrayList<>();
    List<Interval> intervals = new ArrayList<>();

    schedule.forEach(s -> intervals.addAll(s));
    Collections.sort(intervals, (a, b) -> Integer.compare(a.start, b.start));

    int prevEnd = intervals.get(0).end;

    for (Interval interval : intervals) {
      if (interval.start > prevEnd)
        ans.add(new Interval(prevEnd, interval.start));
      prevEnd = Math.max(prevEnd, interval.end);
    }

    return ans;
  }
}
