class Solution {
  public int[] maxNumber(int[] nums1, int[] nums2, int k) {
    int[] ans = new int[k];

    for (int k1 = 0; k1 <= k; ++k1) {
      final int k2 = k - k1;
      if (k1 > nums1.length || k2 > nums2.length)
        continue;
      int[] candidate = merge(maxArray(nums1, k1), maxArray(nums2, k2));
      if (greater(candidate, 0, ans, 0))
        ans = candidate;
    }
    return ans;
  }

  private int[] maxArray(int[] nums, int k) {
    List<Integer> res = new ArrayList<>();
    int toPop = nums.length - k;
    for (final int num : nums) {
      while (!res.isEmpty() && res.get(res.size() - 1) < num && toPop > 0) {
        res.remove(res.size() - 1);
        --toPop;
      }
      res.add(num);
    }
    return res.subList(0, k).stream().mapToInt(i -> i).toArray();
  }

  // Merges nums1 and nums2.
  private int[] merge(int[] nums1, int[] nums2) {
    int[] res = new int[nums1.length + nums2.length];
    for (int i = 0, j = 0, k = 0; k < res.length; ++k)
      res[k] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    return res;
  }

  // Returns true if nums1[i..n) > nums2[j..n).
  private boolean greater(int[] nums1, int i, int[] nums2, int j) {
    while (i < nums1.length && j < nums2.length && nums1[i] == nums2[j]) {
      ++i;
      ++j;
    }
    return j == nums2.length || (i < nums1.length && nums1[i] > nums2[j]);
  }
}
