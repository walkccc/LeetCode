class Solution {
  public String sortSentence(String s) {
    String[] words = s.split(" ");

    Arrays.sort(words, (a, b) -> a.charAt(a.length() - 1) - b.charAt(b.length() - 1));

    StringBuilder sb = new StringBuilder(trim(words[0]));

    for (int i = 1; i < words.length; ++i)
      sb.append(" ").append(trim(words[i]));

    return sb.toString();
  }

  private String trim(final String s) {
    return s.substring(0, s.length() - 1);
  }
}
