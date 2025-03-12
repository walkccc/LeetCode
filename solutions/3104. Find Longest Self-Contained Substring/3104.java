class Solution {
  public int maxSubstringLength(String s) {
    int ans = -1;
    int count[] = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (int n = 1; n <= 26; ++n)
      ans = Math.max(ans, maxSubstringLengthWithNUniqueLetters(s, n, count));

    return ans;
  }

  // Similar to 395. Longest Substring with At Least K Repeating Characters
  private int maxSubstringLengthWithNUniqueLetters(final String s, int n, int[] allCount) {
    int res = -1;
    // the number of unique letters
    int uniqueLetters = 0;
    // the number of letters that have all their frequency in the substring
    int lettersHavingAllFreq = 0;
    int[] count = new int[26];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s.charAt(r) - 'a'] == 1)
        ++uniqueLetters;
      if (count[s.charAt(r) - 'a'] == allCount[s.charAt(r) - 'a'])
        ++lettersHavingAllFreq;
      while (uniqueLetters > n) {
        if (count[s.charAt(l) - 'a'] == allCount[s.charAt(l) - 'a'])
          --lettersHavingAllFreq;
        if (--count[s.charAt(l) - 'a'] == 0)
          --uniqueLetters;
        ++l;
      }
      // Since both the number of unique letters and the number of letters
      // having all their frequency are equal to n, this is a valid window.
      // Implcit: uniqueLetters == n
      if (lettersHavingAllFreq == n && r - l + 1 < s.length())
        res = Math.max(res, r - l + 1);
    }

    return res;
  }
}
