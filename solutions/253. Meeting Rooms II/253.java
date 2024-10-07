class Solution {
  public int minMeetingRooms(int[][] intervals) {
    // Store the end times of each room.
    Queue<Integer> minHeap = new PriorityQueue<>();

    Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

    for (int[] interval : intervals) {
      // There's no overlap, so we can reuse the same room.
      if (!minHeap.isEmpty() && interval[0] >= minHeap.peek())
        minHeap.poll();
      minHeap.offer(interval[1]);
    }

    return minHeap.size();
  }
}
