class Solution {
  public int minMeetingRooms(int[][] intervals) {
    if (intervals.length == 0)
      return 0;

    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);

    Arrays.sort(intervals, (a, b) -> (a[0] - b[0]));
    pq.offer(intervals[0]);

    for (int i = 1; i < intervals.length; ++i) {
      final int[] interval = intervals[i];
      int[] earliestAvailable = pq.poll();
      if (interval[0] >= earliestAvailable[1])
        earliestAvailable[1] = interval[1];
      else
        pq.offer(interval);
      pq.offer(earliestAvailable);
    }

    return pq.size();
  }
}