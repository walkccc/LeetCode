class Solution {
  public int findMaxConsecutiveOnes(int[] nums) {
    int ans = 0;
    int zeros = 0;

    for (int l = 0, r = 0; r < nums.length; ++r) {
      if (nums[r] == 0)
        ++zeros;
      while (zeros == 2)
        if (nums[l++] == 0)
          --zeros;
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
