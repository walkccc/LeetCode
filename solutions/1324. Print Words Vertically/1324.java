class Solution {
  public List<String> printVertically(String s) {
    List<String> ans = new ArrayList<>();
    String[] words = s.split(" ");
    int maxLength = 0;

    for (final String word : words)
      maxLength = Math.max(maxLength, word.length());

    for (int i = 0; i < maxLength; ++i) {
      StringBuilder sb = new StringBuilder();
      for (final String word : words)
        sb.append(i < word.length() ? word.charAt(i) : ' ');
      while (sb.charAt(sb.length() - 1) == ' ')
        sb.deleteCharAt(sb.length() - 1);
      ans.add(sb.toString());
    }

    return ans;
  }
}
