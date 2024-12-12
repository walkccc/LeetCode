class FindSumPairs {
  public FindSumPairs(int[] nums1, int[] nums2) {
    this.nums1 = nums1;
    this.nums2 = nums2;
    for (final int num : nums2)
      count2.merge(num, 1, Integer::sum);
  }

  public void add(int index, int val) {
    count2.merge(nums2[index], -1, Integer::sum);
    nums2[index] += val;
    count2.merge(nums2[index], 1, Integer::sum);
  }

  public int count(int tot) {
    int ans = 0;
    for (final int num : nums1)
      ans += count2.getOrDefault(tot - num, 0);
    return ans;
  }

  private int[] nums1;
  private int[] nums2;
  private Map<Integer, Integer> count2 = new HashMap<>();
}
