class Solution {
  public int minOperations(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    return Arrays.stream(nums).map(num -> Integer.bitCount(num)).sum() +
        (maxNum == 0 ? 0 : (int) (Math.log(maxNum) / Math.log(2)));
  }
}
