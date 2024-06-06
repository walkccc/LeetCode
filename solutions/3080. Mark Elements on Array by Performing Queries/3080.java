class Solution {
  public long[] unmarkedSumArray(int[] nums, int[][] queries) {
    long[] ans = new long[queries.length];
    boolean[] marked = new boolean[nums.length];
    long sum = Arrays.stream(nums).asLongStream().sum();
    // (nums[i], i)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>(
        (a, b)
            -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                             : a.getKey().compareTo(b.getKey()));

    for (int i = 0; i < nums.length; ++i)
      minHeap.offer(new Pair<>(nums[i], i));

    for (int queryIndex = 0; queryIndex < queries.length; ++queryIndex) {
      final int index = queries[queryIndex][0];
      final int k = queries[queryIndex][1];
      if (!marked[index]) {
        marked[index] = true;
        sum -= nums[index];
      }
      for (int popped = 0; popped < k && !minHeap.isEmpty();) {
        final int num = minHeap.peek().getKey();
        final int i = minHeap.poll().getValue();
        if (!marked[i]) {
          marked[i] = true;
          sum -= num;
          ++popped;
        }
      }
      ans[queryIndex] = sum;
    }

    return ans;
  }
}
