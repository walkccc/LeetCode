class Solution {
  public List<String> generatePossibleNextMoves(String s) {
    List<String> ans = new ArrayList<>();

    for (int i = 0; i + 1 < s.length(); ++i)
      if (s.charAt(i) == '+' && s.charAt(i + 1) == '+') {
        StringBuilder sb = new StringBuilder(s);
        sb.setCharAt(i, '-');
        sb.setCharAt(i + 1, '-');
        ans.add(sb.toString());
      }

    return ans;
  }
}
