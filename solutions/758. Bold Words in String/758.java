class Solution {
  public String boldWords(String[] words, String s) {
    final int n = s.length();
    StringBuilder sb = new StringBuilder();
    // bold[i] := true if s[i] should be bolded
    boolean[] bold = new boolean[n];

    int boldEnd = -1; // s[i:boldEnd] should be bolded
    for (int i = 0; i < n; ++i) {
      for (final String word : words)
        if (s.substring(i).startsWith(word))
          boldEnd = Math.max(boldEnd, i + word.length());
      bold[i] = boldEnd > i;
    }

    // Construct the string with the bold tags.
    int i = 0;
    while (i < n)
      if (bold[i]) {
        int j = i;
        while (j < n && bold[j])
          ++j;
        // s[i..j) should be bolded
        sb.append("<b>").append(s.substring(i, j)).append("</b>");
        i = j;
      } else {
        sb.append(s.charAt(i++));
      }

    return sb.toString();
  }
}
