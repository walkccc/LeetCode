class Solution {
  public long maxProduct(String s) {
    final int n = s.length();
    long ans = 1;
    long[] pow = new long[n + 1];       // pow[i] := kBase^i
    long[] hashFromL = new long[n + 1]; // hashFromL[i] = the hash of s[0..i)
    long[] hashFromR = new long[n + 1]; // hashFromR[i] = the hash of s[i..n)
    int[] l = new int[n];               // l[i] := the maximum length of palindromes in s[0..i)
    int[] r = new int[n];               // r[i] := the maximum length of palindromes in s[i..n)

    pow[0] = 1;
    for (int i = 1; i <= n; ++i)
      pow[i] = pow[i - 1] * kBase % kMod;

    for (int i = 1; i <= n; ++i)
      hashFromL[i] = (hashFromL[i - 1] * kBase + val(s.charAt(i - 1))) % kMod;

    for (int i = n - 1; i >= 0; --i)
      hashFromR[i] = (hashFromR[i + 1] * kBase + val(s.charAt(i))) % kMod;

    int mx = 1; // the maximum length of palindromes so far
    for (int i = 0; i < n; i++) {
      if (i - mx - 1 >= 0 && isPalindrome(i - mx - 1, i + 1, hashFromL, hashFromR, pow))
        mx += 2;
      l[i] = mx;
    }

    // Fill in r.
    mx = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (i + mx + 2 <= n && isPalindrome(i, i + mx + 2, hashFromL, hashFromR, pow))
        mx += 2;
      r[i] = mx;
    }

    for (int i = 0; i + 1 < n; ++i)
      ans = Math.max(ans, (long) l[i] * r[i + 1]);

    return ans;
  }

  private static final int kBase = 26;
  private static final int kMod = 1_000_000_007;

  // Returns true if s[l..r) is a palindrome.
  private boolean isPalindrome(int l, int r, long[] hashFromL, long[] hashFromR, long[] pow) {
    return leftHash(l, r, hashFromL, pow) == rightHash(l, r, hashFromR, pow);
  }

  // Returns the hash of s[l..r) from the left.
  private long leftHash(int l, int r, long[] hashFromL, long[] pow) {
    final long hash = (hashFromL[r] - hashFromL[l] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  // Returns the hash of s[l..r) from the right.
  private long rightHash(int l, int r, long[] hashFromR, long[] pow) {
    final long hash = (hashFromR[l] - hashFromR[r] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  private int val(char c) {
    return c - 'a';
  }
}
