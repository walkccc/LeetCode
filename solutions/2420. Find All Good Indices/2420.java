class Solution {
  // Same as 2100. Find Good Days to Rob the Bank
  public List<Integer> goodIndices(int[] nums, int k) {
    final int n = nums.length;
    List<Integer> ans = new ArrayList<>();
    // dec[i] := 1 + the number of continuous decreasing numbers before i
    int[] dec = new int[n];
    // inc[i] := 1 + the number of continuous increasing numbers after i
    int[] inc = new int[n];

    Arrays.fill(dec, 1);
    Arrays.fill(inc, 1);

    for (int i = 1; i < n; ++i)
      if (nums[i - 1] >= nums[i])
        dec[i] = dec[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i)
      if (nums[i] <= nums[i + 1])
        inc[i] = inc[i + 1] + 1;

    for (int i = k; i < n - k; ++i)
      if (dec[i - 1] >= k && inc[i + 1] >= k)
        ans.add(i);

    return ans;
  }
}
