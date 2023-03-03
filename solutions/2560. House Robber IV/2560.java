class Solution {
  public int minCapability(int[] nums, int k) {
    int l = Arrays.stream(nums).min().getAsInt();
    int r = Arrays.stream(nums).max().getAsInt();

    while (l < r) {
      final int m = (l + r) / 2;
      if (stolenHouses(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int stolenHouses(int[] nums, int capacity) {
    int stolen = 0;
    for (int i = 0; i < nums.length; ++i)
      if (nums[i] <= capacity) {
        ++stolen;
        ++i;
      }
    return stolen;
  }
}
