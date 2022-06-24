class Solution {
  public List<String> generateAbbreviations(String word) {
    List<String> ans = new ArrayList<>();
    dfs(word, 0, 0, new StringBuilder(), ans);
    return ans;
  }

  private void dfs(final String word, int i, int count, StringBuilder sb, List<String> ans) {
    if (i == word.length()) {
      final int length = sb.length();
      ans.add(sb.append(getCountString(count)).toString());
      sb.setLength(length);
      return;
    }

    // abbreviate word.charAt(i)
    dfs(word, i + 1, count + 1, sb, ans);
    // keep word.charAt(i), so consume the count as a string
    final int length = sb.length();
    // reset count to 0
    dfs(word, i + 1, 0, sb.append(getCountString(count)).append(word.charAt(i)), ans);
    sb.setLength(length);
  }

  private String getCountString(int count) {
    return count > 0 ? String.valueOf(count) : "";
  }
}
