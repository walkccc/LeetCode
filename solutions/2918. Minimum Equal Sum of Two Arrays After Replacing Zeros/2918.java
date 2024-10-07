class Solution {
  public long minSum(int[] nums1, int[] nums2) {
    long sum1 = Arrays.stream(nums1).asLongStream().sum();
    long sum2 = Arrays.stream(nums2).asLongStream().sum();
    long zero1 = Arrays.stream(nums1).filter(num -> num == 0).count();
    long zero2 = Arrays.stream(nums2).filter(num -> num == 0).count();
    if (zero1 == 0 && sum1 < sum2 + zero2)
      return -1;
    if (zero2 == 0 && sum2 < sum1 + zero1)
      return -1;
    return Math.max(sum1 + zero1, sum2 + zero2);
  }
}
