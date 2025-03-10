class Solution {
  public int minimumLength(String s) {
    int ans = 0;
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (int i = 0; i < 26; ++i)
      if (count[i] > 0)
        ans += count[i] % 2 == 0 ? 2 : 1;

    return ans;
  }
}
