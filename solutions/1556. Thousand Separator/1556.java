class Solution {
  public String thousandSeparator(int n) {
    final String s = Integer.toString(n);
    StringBuilder ans = new StringBuilder();

    for (int i = 0; i < s.length(); ++i) {
      if (i > 0 && (s.length() - i) % 3 == 0)
        ans.append('.');
      ans.append(s.charAt(i));
    }

    return ans.toString();
  }
}
