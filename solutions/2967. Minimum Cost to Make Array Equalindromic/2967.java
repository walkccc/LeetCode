class Solution {
  public long minimumCost(int[] nums) {
    Arrays.sort(nums);
    final int median = nums[nums.length / 2];
    final int nextPalindrome = getPalindrome(median, 1);
    final int prevPalindrome = getPalindrome(median, -1);
    return Math.min(cost(nums, nextPalindrome), cost(nums, prevPalindrome));
  }

  // Returns the cost to change all the numbers to `palindrome`.
  private long cost(int[] nums, int palindrome) {
    return Arrays.stream(nums).mapToLong(num -> Math.abs(palindrome - num)).sum();
  }

  // Returns the palindrome `p`, where p = num + a * delta and a > 0.
  private int getPalindrome(int num, int delta) {
    while (!isPalindrome(num))
      num += delta;
    return num;
  }

  private boolean isPalindrome(int num) {
    final String original = Integer.toString(num);
    final String reversed = new StringBuilder(original).reverse().toString();
    return original.equals(reversed);
  }
}
