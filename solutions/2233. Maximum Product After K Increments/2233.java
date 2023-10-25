class Solution {
  public int maximumProduct(int[] nums, int k) {
    final int kMod = 1_000_000_007;
    long ans = 1;
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (final int num : nums)
      minHeap.offer(num);

    for (int i = 0; i < k; ++i) {
      final int minNum = minHeap.poll();
      minHeap.offer(minNum + 1);
    }

    while (!minHeap.isEmpty()) {
      ans *= minHeap.poll();
      ans %= kMod;
    }

    return (int) ans;
  }
}
