class Solution {
  public int connectSticks(int[] sticks) {
    int ans = 0;
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (final int stick : sticks)
      minHeap.offer(stick);

    while (minHeap.size() > 1) {
      final int x = minHeap.poll();
      final int y = minHeap.poll();
      ans += x + y;
      minHeap.offer(x + y);
    }

    return ans;
  }
}
