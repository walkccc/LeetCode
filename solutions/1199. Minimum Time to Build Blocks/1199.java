class Solution {
  public int minBuildTime(int[] blocks, int split) {
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (final int block : blocks)
      minHeap.offer(block);

    while (minHeap.size() > 1) {
      minHeap.poll();               // the minimum
      final int x = minHeap.poll(); // the second minimum
      minHeap.offer(x + split);
    }

    return minHeap.poll();
  }
}
