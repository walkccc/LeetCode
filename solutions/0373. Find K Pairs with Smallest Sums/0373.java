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
    List<List<Integer>> ans = new ArrayList<>();
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> a.sum - b.sum);

    for (int i = 0; i < k && i < nums1.length; ++i)
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
