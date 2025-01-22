class Solution {
  public boolean isConsecutive(int[] nums) {
    final int n = nums.length;
    final int mx = Arrays.stream(nums).max().getAsInt();
    final int mn = Arrays.stream(nums).min().getAsInt();
    return mx - mn + 1 == n && Arrays.stream(nums).boxed().collect(Collectors.toSet()).size() == n;
  }
}
