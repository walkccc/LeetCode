class Solution {
  public int subarraysDivByK(int[] nums, int k) {
    int ans = 0;
    int prefix = 0;
    int[] count = new int[k];
    count[0] = 1;

    for (final int num : nums) {
      prefix = (prefix + num % k + k) % k;
      ans += count[prefix];
      ++count[prefix];
    }

    return ans;
  }
}
