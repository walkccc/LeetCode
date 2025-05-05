class Solution {
  public int[] topKFrequent(int[] nums, int k) {
    record T(int num, int freq) {}
    final int n = nums.length;
    int[] ans = new int[k];
    Map<Integer, Integer> count = new HashMap<>();
    Queue<T> minHeap = new PriorityQueue<>(Comparator.comparingInt(T::freq));

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final int num = entry.getKey();
      final int freq = entry.getValue();
      minHeap.offer(new T(num, freq));
      if (minHeap.size() > k)
        minHeap.poll();
    }

    for (int i = 0; i < k; ++i)
      ans[i] = minHeap.poll().num;

    return ans;
  }
}
