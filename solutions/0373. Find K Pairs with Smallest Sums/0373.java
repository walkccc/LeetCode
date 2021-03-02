class T {
  public int i;
  public int j;
  public int sum; // nums1[i] + nums2[j]

  public T(int i, int j, int sum) {
    this.i = i;
    this.j = j;
    this.sum = sum;
  }
}

class Solution {
  public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
    if (nums1.length == 0 || nums2.length == 0 || k == 0)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> a.sum - b.sum);

    for (int i = 0; i < k && i < nums1.length; ++i)
      pq.offer(new T(i, 0, nums1[i] + nums2[0]));

    while (!pq.isEmpty() && ans.size() < k) {
      final int i = pq.peek().i;
      final int j = pq.poll().j;
      ans.add(Arrays.asList(nums1[i], nums2[j]));
      if (j + 1 < nums2.length)
        pq.offer(new T(i, j + 1, nums1[i] + nums2[j + 1]));
    }

    return ans;
  }
}
