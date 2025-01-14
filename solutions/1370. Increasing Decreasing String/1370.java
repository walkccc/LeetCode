class Solution {
  public String sortString(String s) {
    StringBuilder sb = new StringBuilder();
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    while (sb.length() < s.length()) {
      for (int i = 0; i < 26; i++) {
        if (count[i] == 0)
          continue;
        sb.append((char) (i + 'a'));
        --count[i];
      }
      for (int i = 25; i >= 0; i--) {
        if (count[i] == 0)
          continue;
        sb.append((char) (i + 'a'));
        --count[i];
      }
    }

    return sb.toString();
  }
}
