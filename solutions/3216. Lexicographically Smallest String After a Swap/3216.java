class Solution {
  public String getSmallestString(String s) {
    char[] chars = s.toCharArray();
    for (int i = 1; i < chars.length; ++i) {
      if (chars[i - 1] % 2 == chars[i] % 2 && chars[i - 1] > chars[i]) {
        final char temp = chars[i - 1];
        chars[i - 1] = chars[i];
        chars[i] = temp;
        return new String(chars);
      }
    }
    return s;
  }
}
