class Solution {
  public String replaceDigits(String s) {
    char[] chars = s.toCharArray();
    for (int i = 1; i < chars.length; i += 2)
      chars[i] += chars[i - 1] - '0';
    return String.valueOf(chars);
  }
}
