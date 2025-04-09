class Solution {
  public String makeGood(String s) {
    StringBuilder sb = new StringBuilder();
    for (char c : s.toCharArray())
      if (sb.length() > 0 && isBadPair(sb.charAt(sb.length() - 1), c))
        sb.deleteCharAt(sb.length() - 1);
      else
        sb.append(c);
    return sb.toString();
  }

  private boolean isBadPair(char a, char b) {
    return a != b && Character.toLowerCase(a) == Character.toLowerCase(b);
  }
}
