class Solution {
  public int minOperations(int[] nums1, int[] nums2) {
    if (nums1.length * 6 < nums2.length || nums2.length * 6 < nums1.length)
      return -1;

    int sum1 = Arrays.stream(nums1).sum();
    int sum2 = Arrays.stream(nums2).sum();
    if (sum1 > sum2)
      return minOperations(nums2, nums1);

    int ans = 0;
    // increasing in `nums1` and decreasing in `nums2`
    int[] count = new int[6];

    Arrays.stream(nums1).forEach(num -> ++count[6 - num]);
    Arrays.stream(nums2).forEach(num -> ++count[num - 1]);

    for (int i = 5; sum2 > sum1;) {
      while (count[i] == 0)
        --i;
      sum1 += i;
      --count[i];
      ++ans;
    }

    return ans;
  }
}
