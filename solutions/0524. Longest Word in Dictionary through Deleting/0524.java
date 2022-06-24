class Solution {
  public String findLongestWord(String s, List<String> d) {
    String ans = "";

    for (final String word : d)
      if (isSubsequence(word, s))
        if (word.length() > ans.length() ||
            word.length() == ans.length() && word.compareTo(ans) < 0)
          ans = word;

    return ans;
  }

  // return true if a is a subsequence of b
  private boolean isSubsequence(final String a, final String b) {
    int i = 0;
    for (final char c : b.toCharArray())
      if (i < a.length() && c == a.charAt(i))
        ++i;
    return i == a.length();
  }
}
