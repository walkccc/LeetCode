class Solution {
  public String longestPrefix(String s) {
    final int kBase = 26;
    final int kMod = 1_000_000_007;
    final int n = s.length();
    int maxLength = 0;
    long pow = 1;
    long prefixHash = 0; // the hash of s[0..i]
    long suffixHash = 0; // the hash of s[j..n)

    for (int i = 0, j = n - 1; i < n - 1; ++i, --j) {
      prefixHash = (prefixHash * kBase + val(s.charAt(i))) % kMod;
      suffixHash = (val(s.charAt(j)) * pow + suffixHash) % kMod;
      pow = pow * kBase % kMod;
      if (prefixHash == suffixHash)
        maxLength = i + 1;
    }

    return s.substring(0, maxLength);
  }

  private int val(char c) {
    return c - 'a';
  }
}
