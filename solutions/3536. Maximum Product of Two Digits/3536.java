class Solution {
  public int maxProduct(int n) {
    char[] s = String.valueOf(n).toCharArray();
    Arrays.sort(s);
    final int sz = s.length;
    return (s[sz - 1] - '0') * (s[sz - 2] - '0');
  }
}
