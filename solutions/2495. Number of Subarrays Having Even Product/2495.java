class Solution {
  public long evenProduct(int[] nums) {
    long ans = 0;
    int numsBeforeEven = 0; // Inclusively.

    // E.g., nums = [1, 0, 1, 1, 0].
    // After we meet the first 0, we set `numsBeforeEven` to 2. Therefore, the
    // num between index 1 to index 3 (the one before next 0) will contribute 2
    // to the ans.
    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] % 2 == 0)
        numsBeforeEven = i + 1;
      ans += numsBeforeEven;
    }

    return ans;
  }
}
