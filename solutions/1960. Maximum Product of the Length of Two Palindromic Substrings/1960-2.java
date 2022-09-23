class Solution {
  public long maxProduct(String s) {
    final int n = s.length();
    long ans = 1;
    long[] pow = new long[n + 1];       // pow[i] := kBase^i
    long[] hashFromL = new long[n + 1]; // hashFromL[i] = hash value of s[0..i)
    long[] hashFromR = new long[n + 1]; // hashFromR[i] = hash value of s[i..n)
    int[] l = new int[n];               // l[i] := max length of palindromes in s[0..i)
    int[] r = new int[n];               // r[i] := max length of palindromes in s[i..n)

    pow[0] = 1;
    for (int i = 1; i <= n; ++i)
      pow[i] = pow[i - 1] * kBase % kMod;

    for (int i = 1; i <= n; ++i)
      hashFromL[i] = (hashFromL[i - 1] * kBase + val(s.charAt(i - 1))) % kMod;

    for (int i = n - 1; i >= 0; --i)
      hashFromR[i] = (hashFromR[i + 1] * kBase + val(s.charAt(i))) % kMod;

    int max = 1; // max length of palindromes so far
    for (int i = 0; i < n; i++) {
      if (i - max - 1 >= 0 && isPalindrome(i - max - 1, i + 1, hashFromL, hashFromR, pow))
        max += 2;
      l[i] = max;
    }

    max = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (i + max + 2 <= n && isPalindrome(i, i + max + 2, hashFromL, hashFromR, pow))
        max += 2;
      r[i] = max;
    }

    for (int i = 0; i + 1 < n; ++i)
      ans = Math.max(ans, (long) l[i] * r[i + 1]);

    return ans;
  }

  private static final int kBase = 26;
  private static final int kMod = 1_000_000_007;

  // true if s[l..r) is palindrome
  private boolean isPalindrome(int l, int r, long[] hashFromL, long[] hashFromR, long[] pow) {
    return leftHash(l, r, hashFromL, pow) == rightHash(l, r, hashFromR, pow);
  }

  private long leftHash(int l, int r, long[] hashFromL, long[] pow) {
    final long hash = (hashFromL[r] - hashFromL[l] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  private long rightHash(int l, int r, long[] hashFromR, long[] pow) {
    final long hash = (hashFromR[l] - hashFromR[r] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  private int val(char c) {
    return c - 'a' + 1;
  }
}
