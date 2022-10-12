class Solution {
  public String maskPII(String S) {
    final int atIndex = S.indexOf('@');
    if (atIndex > 0) {
      S = S.toLowerCase();
      return S.charAt(0) + "*****" + S.substring(atIndex - 1);
    }

    StringBuilder sb = new StringBuilder();
    for (final char c : S.toCharArray())
      if (Character.isDigit(c))
        sb.append(c);

    if (sb.length() == 10)
      return "***-***-" + sb.substring(sb.length() - 4).toString();

    return '+' + "*".repeat(sb.length() - 10) + "-***-***-" +
        sb.substring(sb.length() - 4).toString();
  }
}
