class Solution {
  public int countElements(int[] nums) {
    final int mn = Arrays.stream(nums).min().getAsInt();
    final int mx = Arrays.stream(nums).max().getAsInt();
    return (int) Arrays.stream(nums).filter(num -> mn < num && num < mx).count();
  }
}
