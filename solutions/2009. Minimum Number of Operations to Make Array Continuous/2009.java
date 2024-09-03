class Solution {
  public int minOperations(int[] nums) {
    final int n = nums.length;
    int ans = n;

    Arrays.sort(nums);
    nums = Arrays.stream(nums).distinct().toArray();

    for (int i = 0; i < nums.length; ++i) {
      final int start = nums[i];
      final int end = start + n - 1;
      final int index = firstGreater(nums, end);
      final int uniqueLength = index - i;
      ans = Math.min(ans, n - uniqueLength);
    }

    return ans;
  }

  private int firstGreater(int[] A, int target) {
    final int i = Arrays.binarySearch(A, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
