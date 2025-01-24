class Solution {
  public List<String> stringSequence(String target) {
    List<String> ans = new ArrayList<>();
    StringBuilder sb = new StringBuilder();

    for (final char targetChar : target.toCharArray()) {
      sb.append('a');
      ans.add(sb.toString());
      for (char c = 'b'; c < targetChar; ++c) {
        sb.setCharAt(sb.length() - 1, c);
        ans.add(sb.toString());
      }
    }

    return ans;
  }
}
