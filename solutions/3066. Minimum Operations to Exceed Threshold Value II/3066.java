class Solution {
  public int minOperations(int[] nums, int k) {
    int ans = 0;
    Queue<Long> minHeap = new PriorityQueue<>();

    for (final int num : nums)
      minHeap.add((long) num);

    while (minHeap.size() > 1 && minHeap.peek() < k) {
      final long x = minHeap.poll();
      final long y = minHeap.poll();
      minHeap.add(Math.min(x, y) * 2 + Math.max(x, y));
      ++ans;
    }

    return ans;
  }
}
