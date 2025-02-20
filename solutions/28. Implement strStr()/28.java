class Solution {
  public int strStr(String haystack, String needle) {
    final int m = haystack.length();
    final int n = needle.length();

    for (int i = 0; i < m - n + 1; ++i)
      if (haystack.substring(i, i + n).equals(needle))
        return i;

    return -1;
  }
}
