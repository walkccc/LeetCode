class Solution {
  public boolean isConsecutive(int[] nums) {
    final int n = nums.length;
    final int max = Arrays.stream(nums).max().getAsInt();
    final int min = Arrays.stream(nums).min().getAsInt();
    return max - min + 1 == n &&
        Arrays.stream(nums).boxed().collect(Collectors.toSet()).size() == n;
  }
}
