class Solution {
  public int findMinimumOperations(String s1, String s2, String s3) {
    final int minLength = Math.min(s1.length(), Math.min(s2.length(), s3.length()));
    int i = 0;
    while (i < minLength && s1.charAt(i) == s2.charAt(i) && s2.charAt(i) == s3.charAt(i))
      ++i;
    return i == 0 ? -1 : s1.length() + s2.length() + s3.length() - i * 3;
  }
}
