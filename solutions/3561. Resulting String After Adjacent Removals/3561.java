class Solution {
  public String resultingString(String s) {
    StringBuilder sb = new StringBuilder();

    for (final char c : s.toCharArray())
      if (sb.length() > 0 && (Math.abs(sb.charAt(sb.length() - 1) - c) == 1 ||
                              Math.abs(sb.charAt(sb.length() - 1) - c) == 25))
        sb.deleteCharAt(sb.length() - 1);
      else
        sb.append(c);

    return sb.toString();
  }
}
