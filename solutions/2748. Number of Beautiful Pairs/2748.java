class Solution {
  public int countBeautifulPairs(int[] nums) {
    int ans = 0;

    for (int i = 0; i < nums.length; ++i)
      for (int j = i + 1; j < nums.length; ++j)
        if (gcd(firstDigit(nums[i]), lastDigit(nums[j])) == 1)
          ++ans;

    return ans;
  }

  private int firstDigit(int num) {
    return Integer.parseInt(Integer.toString(num).substring(0, 1));
  }

  private int lastDigit(int num) {
    return num % 10;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
