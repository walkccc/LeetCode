class Solution {
  public boolean isPossible(int[] target) {
    if (target.length == 1)
      return target[0] == 1;

    long sum = Arrays.stream(target).asLongStream().sum();
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    for (final int num : target)
      maxHeap.offer(num);

    while (maxHeap.peek() > 1) {
      final long mx = maxHeap.poll();
      final long restSum = sum - mx;
      // Only occurs if n == 2.
      if (restSum == 1)
        return true;
      final long updated = mx % restSum;
      // updated == 0 (invalid) or didn't change.
      if (updated == 0 || updated == mx)
        return false;
      maxHeap.offer((int) updated);
      sum = sum - mx + updated;
    }

    return true;
  }
}
