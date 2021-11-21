class Solution {
  public int minMeetingRooms(int[][] intervals) {
    if (intervals.length == 0)
      return 0;

    // store end times of each room
    PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);

    Arrays.sort(intervals, (a, b) -> (a[0] - b[0]));

    for (int[] interval : intervals) {
      if (!pq.isEmpty() && interval[0] >= pq.peek())
        pq.poll(); // no overlap, we can reuse the same room
      pq.offer(interval[1]);
    }

    return pq.size();
  }
}
