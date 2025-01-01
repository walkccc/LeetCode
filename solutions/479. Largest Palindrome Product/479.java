class Solution {
  public int largestPalindrome(int n) {
    if (n == 1)
      return 9;

    final int kMod = 1337;
    final int upper = (int) Math.pow(10, n) - 1;
    final int lower = (int) Math.pow(10, n - 1) - 1;

    for (int i = upper; i > lower; --i) {
      final long cand = getPalindromeCandidate(i);
      for (long j = upper; j * j >= cand; --j)
        if (cand % j == 0)
          return (int) (cand % kMod);
    }

    throw new IllegalArgumentException();
  }

  private long getPalindromeCandidate(int i) {
    final String reversed = new StringBuilder().append(i).reverse().toString();
    return Long.valueOf(i + reversed);
  }
}
