class Solution {
  public String licenseKeyFormatting(String s, int k) {
    StringBuilder sb = new StringBuilder();
    int length = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
      if (s.charAt(i) == '-')
        continue;
      if (length > 0 && length % k == 0)
        sb.append('-');
      sb.append(Character.toUpperCase(s.charAt(i)));
      ++length;
    }

    return sb.reverse().toString();
  }
}
