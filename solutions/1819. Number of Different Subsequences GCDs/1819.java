class Solution {
  public int countDifferentSubsequenceGCDs(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    int ans = 0;
    // factor[i] := gcd of nums having factor i
    int[] factor = new int[maxNum + 1];

    for (final int num : nums)
      for (int i = 1; i * i <= num; ++i)
        if (num % i == 0) {
          final int j = num / i;
          factor[i] = gcd(factor[i], num);
          factor[j] = gcd(factor[j], num);
        }

    for (int i = 1; i <= maxNum; ++i)
      if (factor[i] == i)
        ++ans;

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
