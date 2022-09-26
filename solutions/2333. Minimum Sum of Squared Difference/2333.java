class Solution {
  public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
    int[] diff = getDiff(nums1, nums2);
    int k = k1 + k2;
    if (Arrays.stream(diff).asLongStream().sum() <= k)
      return 0;

    Map<Integer, Integer> count = new HashMap<>();
    // (num, freq)
    Queue<Pair<Integer, Integer>> maxHeap = new PriorityQueue<>((a, b) -> b.getKey() - a.getKey());

    for (final int d : diff)
      if (d != 0)
        count.merge(d, 1, Integer::sum);

    for (Map.Entry<Integer, Integer> entry : count.entrySet())
      maxHeap.offer(new Pair<>(entry.getKey(), entry.getValue()));

    while (k > 0) {
      Pair<Integer, Integer> node = maxHeap.poll();
      final int maxNum = node.getKey();
      final int maxNumFreq = node.getValue();
      // buck decrease in this turn
      final int numDecreased = Math.min(k, maxNumFreq);
      k -= numDecreased;
      if (maxNumFreq > numDecreased)
        maxHeap.offer(new Pair<>(maxNum, maxNumFreq - numDecreased));
      if (!maxHeap.isEmpty() && maxHeap.peek().getKey() + 1 == maxNum) {
        Pair<Integer, Integer> secondNode = maxHeap.poll();
        final int secondMaxNum = secondNode.getKey();
        final int secondMaxNumFreq = secondNode.getValue();
        maxHeap.offer(new Pair<>(secondMaxNum, secondMaxNumFreq + numDecreased));
      } else if (maxNum > 1) {
        maxHeap.offer(new Pair<>(maxNum - 1, numDecreased));
      }
    }

    long ans = 0;
    while (!maxHeap.isEmpty()) {
      Pair<Integer, Integer> node = maxHeap.poll();
      final int num = node.getKey();
      final int freq = node.getValue();
      ans += (long) num * num * freq;
    }

    return ans;
  }

  private int[] getDiff(int[] nums1, int[] nums2) {
    int[] diff = new int[nums1.length];
    for (int i = 0; i < nums1.length; ++i)
      diff[i] = Math.abs(nums1[i] - nums2[i]);
    return diff;
  }
}
