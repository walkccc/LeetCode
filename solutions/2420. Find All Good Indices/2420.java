class Solution {
  public List<Integer> goodIndices(int[] nums, int k) {
    final int n = nums.length;
    List<Integer> ans = new ArrayList<>();
    int[] dec = new int[n]; // dec[i] := continuous decreasing before i
    int[] inc = new int[n]; // inc[i] := continuous increasing before i

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
