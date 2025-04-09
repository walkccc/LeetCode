class Solution {
  public int[] getFinalState(int[] nums, int k, int multiplier) {
    int[] ans = new int[nums.length];
    // (nums[i], i)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>(
        new PriorityQueue<>(Comparator.comparingInt(Pair<Integer, Integer>::getKey)
                                .thenComparingInt(Pair<Integer, Integer>::getValue)));

    for (int i = 0; i < nums.length; ++i)
      minHeap.offer(new Pair<>(nums[i], i));

    while (k-- > 0) {
      final int num = minHeap.peek().getKey();
      final int i = minHeap.poll().getValue();
      minHeap.offer(new Pair<>(num * multiplier, i));
    }

    while (!minHeap.isEmpty()) {
      final int num = minHeap.peek().getKey();
      final int i = minHeap.poll().getValue();
      ans[i] = num;
    }

    return ans;
  }
}
