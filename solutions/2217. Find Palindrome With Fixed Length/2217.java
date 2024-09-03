class Solution {
  public long[] kthPalindrome(int[] queries, int intLength) {
    final int start = (int) Math.pow(10, (intLength + 1) / 2 - 1);
    final int end = (int) Math.pow(10, (intLength + 1) / 2);
    final int mul = (int) Math.pow(10, intLength / 2);
    long[] ans = new long[queries.length];

    for (int i = 0; i < queries.length; ++i)
      if (start + queries[i] > end)
        ans[i] = -1;
      else
        ans[i] = getKthPalindrome(queries[i], start, mul, intLength);

    return ans;
  }

  private long getKthPalindrome(int q, int start, int mul, int intLength) {
    final long prefix = start + q - 1;
    return prefix * mul + reverse(intLength % 2 == 0 ? prefix : prefix / 10);
  }

  long reverse(long num) {
    long res = 0;
    while (num > 0) {
      res = res * 10 + num % 10;
      num /= 10;
    }
    return res;
  }
}
