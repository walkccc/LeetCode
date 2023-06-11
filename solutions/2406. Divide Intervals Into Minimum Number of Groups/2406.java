class Solution {
  // Similar to 253. Meeting Rooms II
  public int minGroups(int[][] intervals) {
    // Store `right`s.
    Queue<Integer> minHeap = new PriorityQueue<>((a, b) -> a - b);

    Arrays.sort(intervals, (a, b) -> (a[0] - b[0]));

    for (int[] interval : intervals) {
      if (!minHeap.isEmpty() && interval[0] > minHeap.peek())
        minHeap.poll(); // No overlap, we can reuse the same group.
      minHeap.offer(interval[1]);
    }

    return minHeap.size();
  }
}
