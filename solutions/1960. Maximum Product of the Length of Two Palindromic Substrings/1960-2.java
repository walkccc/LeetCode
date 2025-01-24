class Solution {
  public long maxProduct(String s) {
    final int n = s.length();
    long ans = 1;
    long[] pows = new long[n + 1]; // pows[i] := kBase^i % kHash
    // hashL[i] = the hash of the first i letters of s, where hashL[i] =
    // (26^(i - 1) * s[0] + 26^(i - 2) * s[1] + ... + s[i - 1]) % kHash
    long[] hashL = new long[n + 1];
    // hashR[i] = the hash of the last i letters of s, where hashR[i] =
    // (26^(i - 1) * s[-1] + 26^(i - 2) * s[-2] + ... + s[-i]) % kHash
    long[] hashR = new long[n + 1];
    // maxLeft[i] := the maximum odd length of palindromes in s[0..i]
    int[] maxLeft = new int[n];
    // maxRight[i] := the maximum odd length of palindromes in s[i..n - 1]
    int[] maxRight = new int[n];

    pows[0] = 1;
    for (int i = 1; i <= n; ++i)
      pows[i] = pows[i - 1] * kBase % kHash;

    for (int i = 1; i <= n; ++i)
      hashL[i] = (hashL[i - 1] * kBase + val(s.charAt(i - 1))) % kHash;

    for (int i = n - 1; i >= 0; --i)
      hashR[i] = (hashR[i + 1] * kBase + val(s.charAt(i))) % kHash;

    int maxLength = 1;
    for (int r = 0; r < n; ++r) {
      final int l = (r - maxLength - 2) + 1;
      if (l >= 0 && isPalindrome(l, r + 1, hashL, hashR, pows))
        maxLength += 2;
      maxLeft[r] = maxLength;
    }

    maxLength = 1;
    for (int l = n - 1; l >= 0; --l) {
      final int r = (l + maxLength + 2) - 1;
      if (r < n && isPalindrome(l, r + 1, hashL, hashR, pows))
        maxLength += 2;
      maxRight[l] = maxLength;
    }

    for (int i = 1; i < n; ++i)
      ans = Math.max(ans, (long) maxLeft[i - 1] * maxRight[i]);

    return ans;
  }

  private static final int kBase = 26;
  private static final int kHash = 1_000_000_007;

  private static int val(char c) {
    return c - 'a';
  }

  // Returns true if s[l..r) is a palindrome.
  private boolean isPalindrome(int l, int r, long[] hashL, long[] hashR, long[] pows) {
    return getLeftRollingHash(l, r, hashL, pows) == getRightRollingHash(l, r, hashR, pows);
  }

  // Returns the left rolling hash of s[l..r).
  private long getLeftRollingHash(int l, int r, long[] hashL, long[] pows) {
    final long h = (hashL[r] - hashL[l] * pows[r - l]) % kHash;
    return h < 0 ? h + kHash : h;
  }

  // Returns the right rolling hash of s[l..r).
  private long getRightRollingHash(int l, int r, long[] hashR, long[] pows) {
    final long h = (hashR[l] - hashR[r] * pows[r - l]) % kHash;
    return h < 0 ? h + kHash : h;
  }
}
