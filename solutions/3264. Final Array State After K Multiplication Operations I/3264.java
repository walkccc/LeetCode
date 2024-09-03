class Solution {
  public int[] getFinalState(int[] nums, int k, int multiplier) {
    int[] ans = new int[nums.length];
    // (nums[i], i)
    Queue<int[]> minHeap = new PriorityQueue<>(
        (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

    for (int i = 0; i < nums.length; ++i)
      minHeap.offer(new int[] {nums[i], i});

    while (k-- > 0) {
      final int num = minHeap.peek()[0];
      final int i = minHeap.poll()[1];
      minHeap.offer(new int[] {num * multiplier, i});
    }

    while (!minHeap.isEmpty()) {
      final int num = minHeap.peek()[0];
      final int i = minHeap.poll()[1];
      ans[i] = num;
    }

    return ans;
  }
}
