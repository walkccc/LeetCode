class Solution {
  public int countVowelSubstrings(String word) {
    return countVowelSubstringsAtMost(word, 5) - countVowelSubstringsAtMost(word, 4);
  }

  private int countVowelSubstringsAtMost(final String s, int goal) {
    int ans = 0;
    int k = goal;
    int[] count = new int[26];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (!isVowel(s.charAt(r))) { // Fresh start.
        l = r + 1;
        k = goal;
        count = new int[26];
        continue;
      }
      if (++count[s.charAt(r) - 'a'] == 1)
        --k;
      while (k == -1)
        if (--count[s.charAt(l++) - 'a'] == 0)
          ++k;
      ans += r - l + 1; // s[l..r], s[l + 1..r], ..., s[r]
    }

    return ans;
  }

  private boolean isVowel(char c) {
    return "aeiou".indexOf(c) != -1;
  }
}
