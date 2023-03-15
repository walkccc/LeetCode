class Solution {
  public int maxSubArray(int[] nums) {
    return divideAndConquer(nums, 0, nums.length - 1).mid;
  }

  private T divideAndConquer(int[] nums, int l, int r) {
    if (l == r)
      return new T(nums[l], nums[l], nums[l], nums[l]);

    final int m = (l + r) / 2;
    final T t1 = divideAndConquer(nums, l, m);
    final T t2 = divideAndConquer(nums, m + 1, r);

    final int left = Math.max(t1.left, t1.sum + t2.left);
    final int right = Math.max(t1.right + t2.sum, t2.right);
    final int mid = Math.max(t1.right + t2.left, Math.max(t1.mid, t2.mid));
    final int sum = t1.sum + t2.sum;
    return new T(left, right, mid, sum);
  }

  private record T(int left,   // Sum of the subarray w/ max sum (starting from the first num)
                   int right,  // Sum of the subarray w/ max sum (ending at the the last num)
                   int mid,    // Sum of the subarray w/ max sum,
                   int sum) {} // Sum of the whole array
}
