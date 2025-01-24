class Solution {
  public String answerString(String word, int numFriends) {
    if (numFriends == 1)
      return word;
    final String s = lastSubstring(word);
    final int sz = word.length() - numFriends + 1;
    return s.substring(0, Math.min(s.length(), sz));
  }

  // Same as 1163. Last Substring in Lexicographical Order
  private String lastSubstring(String s) {
    int i = 0;
    int j = 1;
    int k = 0; // the number of the same letters of s[i..n) and s[j..n)

    while (j + k < s.length())
      if (s.charAt(i + k) == s.charAt(j + k)) {
        ++k;
      } else if (s.charAt(i + k) > s.charAt(j + k)) {
        // Skip s[j..j + k) and advance to s[j + k + 1] to find a possible
        // lexicographically larger substring since s[i..i + k) == s[j..j + k)
        // and s[i + k] > s[j + k).
        j = j + k + 1;
        k = 0;
      } else {
        // Skip s[i..i + k) and advance to s[i + k + 1] or s[j] to find a
        // possible lexicographically larger substring since
        // s[i..i + k) == s[j..j + k) and s[i + k] < s[j + k).
        // Note that it's unnecessary to explore s[i + k + 1..j) if
        // i + k + 1 < j since they are already explored by j.
        i = Math.max(i + k + 1, j);
        j = i + 1;
        k = 0;
      }

    return s.substring(i);
  }
}
