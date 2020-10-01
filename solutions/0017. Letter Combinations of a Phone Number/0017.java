class Solution {
  public List<String> letterCombinations(String digits) {
    if (digits.isEmpty())
      return new ArrayList<>();

    List<String> ans = new ArrayList<>();

    dfs(digits, 0, new StringBuilder(), ans);

    return ans;
  }

  private static final String[] digitToLetters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

  private void dfs(String digits, int i, StringBuilder path, List<String> ans) {
    if (i == digits.length()) {
      ans.add(path.toString());
      return;
    }

    for (final char c : digitToLetters[digits.charAt(i) - '0'].toCharArray()) {
      path.append(c);
      dfs(digits, i + 1, path, ans);
      path.deleteCharAt(path.length() - 1);
    }
  }
}