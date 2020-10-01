class Solution {
  public String findLongestWord(String s, List<String> d) {
    String ans = "";

    for (final String word : d) {
      int i = 0;
      for (char c : s.toCharArray())
        if (i < word.length() && c == word.charAt(i))
          ++i;
      if (i == word.length())
        if (word.length() > ans.length() || word.length() == ans.length() && word.compareTo(ans) < 0)
          ans = word;
    }

    return ans;
  }
}