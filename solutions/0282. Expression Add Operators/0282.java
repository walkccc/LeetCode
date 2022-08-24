class Solution {
  public List<String> addOperators(String num, int target) {
    List<String> ans = new ArrayList<>();
    dfs(num, target, 0, 0, 0, new StringBuilder(), ans);
    return ans;
  }

  private void dfs(String num, int target, int s, long prev, long eval, StringBuilder sb,
                   List<String> ans) {
    if (s == num.length()) {
      if (eval == target)
        ans.add(sb.toString());
      return;
    }

    for (int i = s; i < num.length(); ++i) {
      if (i > s && num.charAt(s) == '0')
        return;
      final long curr = Long.parseLong(num.substring(s, i + 1));
      final int length = sb.length();
      if (s == 0) { // first num
        dfs(num, target, i + 1, curr, curr, sb.append(curr), ans);
        sb.setLength(length);
      } else {
        dfs(num, target, i + 1, curr, eval + curr, sb.append("+").append(curr), ans);
        sb.setLength(length);
        dfs(num, target, i + 1, -curr, eval - curr, sb.append("-").append(curr), ans);
        sb.setLength(length);
        dfs(num, target, i + 1, prev * curr, eval - prev + prev * curr, sb.append("*").append(curr),
            ans);
        sb.setLength(length);
      }
    }
  }
}
