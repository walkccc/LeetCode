class Solution {
  public String addBoldTag(String s, String[] dict) {
    final int n = s.length();

    StringBuilder sb = new StringBuilder();
    boolean[] bold = new boolean[n]; // bold[i] := true if s[i] should be bolded

    int boldEnd = -1; // s[i..boldEnd) should be bolded
    for (int i = 0; i < n; ++i) {
      for (final String word : dict)
        if (s.substring(i).startsWith(word))
          boldEnd = Math.max(boldEnd, i + word.length());
      bold[i] = boldEnd > i;
    }

    // construct the string with bold tags
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
