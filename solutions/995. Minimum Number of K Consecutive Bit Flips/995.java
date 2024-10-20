class Solution {
  public int minKBitFlips(int[] nums, int k) {
    int ans = 0;
    int flippedTime = 0;

    for (int i = 0; i < nums.length; ++i) {
      if (i >= k && nums[i - k] == 2)
        --flippedTime;
      if (flippedTime % 2 == nums[i]) {
        if (i + k > nums.length)
          return -1;
        ++ans;
        ++flippedTime;
        nums[i] = 2;
      }
    }

    return ans;
  }
}
