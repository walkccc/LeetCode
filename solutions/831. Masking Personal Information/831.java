class Solution {
  public String maskPII(String s) {
    final int atIndex = s.indexOf('@');
    if (atIndex > 0) {
      s = s.toLowerCase();
      return s.charAt(0) + "*****" + s.substring(atIndex - 1);
    }

    StringBuilder sb = new StringBuilder();
    for (final char c : s.toCharArray())
      if (Character.isDigit(c))
        sb.append(c);

    if (sb.length() == 10)
      return "***-***-" + sb.substring(sb.length() - 4).toString();
    return '+' + "*".repeat(sb.length() - 10) + "-***-***-" +
        sb.substring(sb.length() - 4).toString();
  }
}
