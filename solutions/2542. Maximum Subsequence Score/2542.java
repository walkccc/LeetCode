class Solution {
  // Same as 1383. Maximum Performance of a Team
  public long maxScore(int[] nums1, int[] nums2, int k) {
    long ans = 0;
    long sum = 0;
    // (nums2[i], nums1[i]) sorted by nums2[i] in descending order
    Pair<Integer, Integer>[] A = new Pair[nums1.length];
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (int i = 0; i < nums1.length; ++i)
      A[i] = new Pair<>(nums2[i], nums1[i]);

    Arrays.sort(A, (a, b) -> b.getKey().compareTo(a.getKey()));

    for (Pair<Integer, Integer> a : A) {
      final int num2 = a.getKey();
      final int num1 = a.getValue();
      minHeap.offer(num1);
      sum += num1;
      if (minHeap.size() > k)
        sum -= minHeap.poll();
      if (minHeap.size() == k)
        ans = Math.max(ans, sum * num2);
    }

    return ans;
  }
}
