class Solution {
  public int countPartitions(int[] nums) {
    // If we add the same number in the left subarray and remove it from the
    // right subarray, then the difference remains the same parity. So, just
    // return the number of ways to partition the array into two subarrays when
    // the array sum is even.
    return Arrays.stream(nums).sum() % 2 == 0 ? nums.length - 1 : 0;
  }
}
