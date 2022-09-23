class Solution {
  public String licenseKeyFormatting(String S, int K) {
    StringBuilder sb = new StringBuilder();
    int length = 0;

    for (int i = S.length() - 1; i >= 0; --i) {
      if (S.charAt(i) == '-')
        continue;
      if (length > 0 && length % K == 0)
        sb.append('-');
      sb.append(Character.toUpperCase(S.charAt(i)));
      ++length;
    }

    return sb.reverse().toString();
  }
}
