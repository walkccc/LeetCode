class Solution {
  public int distinctAverages(int[] nums) {
    final int n = nums.length;
    Set<Integer> sums = new HashSet<>();

    Arrays.sort(nums);

    for (int i = 0; i < n / 2; ++i)
      sums.add(nums[i] + nums[n - i - 1]);

    return sums.size();
  }
}
