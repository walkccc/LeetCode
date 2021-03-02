class Solution {
  public int longestSubstring(String s, int k) {
    int ans = 0;

    for (int n = 1; n <= 26; ++n)
      ans = Math.max(ans, longestSubstringWithNUniqueCharacters(s, k, n));

    return ans;
  }

  private int longestSubstringWithNUniqueCharacters(final String s, int k, int n) {
    int ans = 0;
    int uniqueChars = 0; // unique chars in current substring s[l..r]
    int noLessThanK = 0; // # of chars >= k
    int[] count = new int[128];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (count[s.charAt(r)] == 0)
        ++uniqueChars;
      if (++count[s.charAt(r)] == k)
        ++noLessThanK;
      while (uniqueChars > n) {
        if (count[s.charAt(l)] == k)
          --noLessThanK;
        if (--count[s.charAt(l)] == 0)
          --uniqueChars;
        ++l;
      }
      if (noLessThanK == n) // unique chars also == n
        ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
