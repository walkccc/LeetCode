class Solution {
  public String reverseStr(String s, int k) {
    char[] chars = s.toCharArray();

    for (int i = 0; i < chars.length; i += 2 * k) {
      int l = i;
      int r = Math.min(i + k - 1, chars.length - 1);
      while (l < r) {
        char temp = chars[l];
        chars[l++] = chars[r];
        chars[r--] = temp;
      }
    }

    return new String(chars);
  }
}