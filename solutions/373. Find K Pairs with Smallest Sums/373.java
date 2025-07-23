class Solution {
  public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
    record T(int i, int j, int sum) {}
    List<List<Integer>> ans = new ArrayList<>();
    Queue<T> minHeap = new PriorityQueue<>(Comparator.comparingInt(T::sum));

    for (int i = 0; i < Math.min(k, nums1.length); ++i)
      minHeap.offer(new T(i, 0, nums1[i] + nums2[0]));

    while (!minHeap.isEmpty() && ans.size() < k) {
      final int i = minHeap.peek().i;
      final int j = minHeap.poll().j;
      ans.add(Arrays.asList(nums1[i], nums2[j]));
      if (j + 1 < nums2.length)
        minHeap.offer(new T(i, j + 1, nums1[i] + nums2[j + 1]));
    }

    return ans;
  }
}
