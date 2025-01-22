class Solution {
  public int maximumTripletValue(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int[] rightMax = new int[n]; // rightMax[i] := max(nums[i + 1..n))
    TreeSet<Integer> leftSortedSet = new TreeSet<>(Arrays.asList(nums[0]));

    for (int i = n - 2; i >= 0; --i)
      rightMax[i] = Math.max(nums[i + 1], rightMax[i + 1]);

    for (int j = 1; j < n - 1; ++j) {
      Integer lower = leftSortedSet.lower(nums[j]);
      if (lower != null && rightMax[j] > nums[j])
        ans = Math.max(ans, lower - nums[j] + rightMax[j]);
      leftSortedSet.add(nums[j]);
    }

    return ans;
  }
}
