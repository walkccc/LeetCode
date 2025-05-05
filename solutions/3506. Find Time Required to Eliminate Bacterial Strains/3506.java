class Solution {
  public long minEliminationTime(int[] timeReq, int splitTime) {
    PriorityQueue<Long> minHeap = new PriorityQueue<>();

    for (final long time : timeReq)
      minHeap.offer(time);

    minHeap.poll();

    while (true) {
      final long bacterial = splitTime + minHeap.peek();
      minHeap.poll();
      if (minHeap.isEmpty())
        return bacterial;
      if (bacterial > minHeap.peek()) {
        minHeap.poll();
        minHeap.offer(bacterial);
      }
    }
  }
}
