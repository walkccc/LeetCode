class Solution {
  public List<String> findStrobogrammatic(int n) {
    return helper(n, n);
  }

  private List<String> helper(int n, int k) {
    if (n == 0)
      return List.of("");
    if (n == 1)
      return List.of("0", "1", "8");

    List<String> ans = new ArrayList<>();

    for (final String inner : helper(n - 2, k)) {
      if (n < k)
        ans.add("0" + inner + "0");
      ans.add("1" + inner + "1");
      ans.add("6" + inner + "9");
      ans.add("8" + inner + "8");
      ans.add("9" + inner + "6");
    }

    return ans;
  }
}
