class Solution {
  public int firstUniqChar(String s) {
    int[] count = new int[128];

    for (final char c : s.toCharArray())
      ++count[c];

    for (int i = 0; i < s.length(); ++i)
      if (count[s.charAt(i)] == 1)
        return i;

    return -1;
  }
}
