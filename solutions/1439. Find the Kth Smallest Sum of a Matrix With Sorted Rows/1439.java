class Solution {
  public int kthSmallest(int[][] mat, int k) {
    int[] row = mat[0];

    for (int i = 1; i < mat.length; ++i)
      row = kSmallestPairSums(row, mat[i], k);

    return row[k - 1];
  }

  private record T(int i, int j, int sum) {}

  // Similar to 373. Find K Pairs with Smallest Sums
  private int[] kSmallestPairSums(int[] nums1, int[] nums2, int k) {
    List<Integer> ans = new ArrayList<>();
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.sum, b.sum));

    for (int i = 0; i < k && i < nums1.length; ++i)
      minHeap.offer(new T(i, 0, nums1[i] + nums2[0]));

    while (!minHeap.isEmpty() && ans.size() < k) {
      final int i = minHeap.peek().i;
      final int j = minHeap.poll().j;
      ans.add(nums1[i] + nums2[j]);
      if (j + 1 < nums2.length)
        minHeap.offer(new T(i, j + 1, nums1[i] + nums2[j + 1]));
    }

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
