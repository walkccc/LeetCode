class Solution {
  // Similar to 253. Meeting Rooms II
  public int minGroups(int[][] intervals) {
    // Stores `right`s.
    Queue<Integer> minHeap = new PriorityQueue<>();

    Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));

    for (int[] interval : intervals) {
      // There's no overlap, so we can reuse the same group.
      if (!minHeap.isEmpty() && interval[0] > minHeap.peek())
        minHeap.poll();
      minHeap.offer(interval[1]);
    }

    return minHeap.size();
  }
}
