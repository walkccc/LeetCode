class Solution {
  public String longestPrefix(String s) {
    final int BASE = 26;
    final long HASH = 8_417_508_174_513L;
    final int n = s.length();
    int maxLength = 0;
    long pow = 1;
    long prefixHash = 0; // the hash of s[0..i]
    long suffixHash = 0; // the hash of s[j..n)

    for (int i = 0, j = n - 1; i < n - 1; ++i, --j) {
      prefixHash = (prefixHash * BASE + val(s.charAt(i))) % HASH;
      suffixHash = (val(s.charAt(j)) * pow + suffixHash) % HASH;
      pow = pow * BASE % HASH;
      if (prefixHash == suffixHash)
        maxLength = i + 1;
    }

    return s.substring(0, maxLength);
  }

  private int val(char c) {
    return c - 'a';
  }
}
