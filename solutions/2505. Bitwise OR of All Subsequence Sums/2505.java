class Solution {
  public long subsequenceSumOr(int[] nums) {
    long ans = 0;
    long prefix = 0;

    for (final int num : nums) {
      prefix += num;
      ans |= num | prefix;
    }

    return ans;
  }
}
