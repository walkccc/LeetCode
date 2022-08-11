class Solution {
  public int minBuildTime(int[] blocks, int split) {
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (final int block : blocks)
      minHeap.offer(block);

    while (minHeap.size() > 1) {
      minHeap.poll();               // smallest
      final int x = minHeap.poll(); // 2nd smallest
      minHeap.offer(x + split);
    }

    return minHeap.poll();
  }
}
