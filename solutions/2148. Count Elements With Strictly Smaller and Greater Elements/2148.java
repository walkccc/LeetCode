class Solution {
  public int countElements(int[] nums) {
    final int min = Arrays.stream(nums).min().getAsInt();
    final int max = Arrays.stream(nums).max().getAsInt();
    return (int) Arrays.stream(nums).filter(num -> min < num && num < max).count();
  }
}
