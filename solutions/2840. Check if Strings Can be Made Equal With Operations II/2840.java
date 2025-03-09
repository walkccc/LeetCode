class Solution {
  public boolean checkStrings(String s1, String s2) {
    int[][] count = new int[2][26];

    for (int i = 0; i < s1.length(); ++i) {
      ++count[i % 2][s1.charAt(i) - 'a'];
      --count[i % 2][s2.charAt(i) - 'a'];
    }

    for (int i = 0; i < 26; ++i)
      if (count[0][i] > 0 || count[1][i] > 0)
        return false;

    return true;
  }
}
