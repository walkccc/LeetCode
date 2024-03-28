class Solution {
  public int minMeetingRooms(int[][] intervals) {
    Arrays.sort(intervals, (a, b) -> (a[0] - b[0]));

    // Store the end times of each room.
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (int[] interval : intervals) {
      // There's no overlap, so we can reuse the same room.
      if (!minHeap.isEmpty() && interval[0] >= minHeap.peek())
        minHeap.poll();
      minHeap.offer(interval[1]);
    }

    return minHeap.size();
  }
}
