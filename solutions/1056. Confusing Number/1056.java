class Solution {
  public boolean confusingNumber(int n) {
    final String s = String.valueOf(n);
    final char[] rotated = {'0', '1', 'x', 'x', 'x', 'x', '9', 'x', '8', '6'};
    StringBuilder sb = new StringBuilder();

    for (int i = s.length() - 1; i >= 0; --i) {
      if (rotated[s.charAt(i) - '0'] == 'x')
        return false;
      sb.append(rotated[s.charAt(i) - '0']);
    }

    return !sb.toString().equals(s);
  }
}
