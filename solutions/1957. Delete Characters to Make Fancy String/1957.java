class Solution {
  public String makeFancyString(String s) {
    StringBuilder sb = new StringBuilder();
    for (char c : s.toCharArray())
      if (sb.length() < 2 || //
          sb.charAt(sb.length() - 1) != c || sb.charAt(sb.length() - 2) != c)
        sb.append(c);
    return sb.toString();
  }
}
