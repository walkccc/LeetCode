class Solution {
  public int maxDiff(int num) {
    final String s = String.valueOf(num);
    final int firstNot9 = firstNot(s, '9', '9');
    final int firstNot01 = firstNot(s, '0', '1');
    final String a = s.replace(s.charAt(firstNot9), '9');
    final String b = s.replace(s.charAt(firstNot01), firstNot01 == 0 ? '1' : '0');
    return Integer.parseInt(a) - Integer.parseInt(b);
  }

  private int firstNot(final String s, char a, char b) {
    for (int i = 0; i < s.length(); ++i)
      if (s.charAt(i) != a && s.charAt(i) != b)
        return i;
    return 0;
  }
}
