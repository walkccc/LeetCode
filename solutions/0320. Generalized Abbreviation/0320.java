class Solution {
  public List<String> generateAbbreviations(String word) {
    List<String> ans = new ArrayList<>();

    dfs(word, 0, 0, new StringBuilder(), ans);

    return ans;
  }

  private void dfs(final String word, int i, int count, StringBuilder path, List<String> ans) {
    if (i == word.length()) {
      final int length = path.length();
      ans.add(path.append(getCountString(count)).toString());
      path.setLength(length);
      return;
    }

    // abbreviate word.charAt(i)
    dfs(word, i + 1, count + 1, path, ans);
    // keep word.charAt(i), so consume the count as a string
    final int length = path.length();
    dfs(word, i + 1, 0, path.append(getCountString(count)).append(word.charAt(i)), ans); // reset count to 0
    path.setLength(length);
  }

  private String getCountString(int count) {
    return count > 0 ? String.valueOf(count) : "";
  }
}