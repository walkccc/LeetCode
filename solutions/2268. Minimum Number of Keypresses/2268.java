class Solution {
  public int minimumKeypresses(String s) {
    int ans = 0;
    Integer[] count = new Integer[26];
    Arrays.fill(count, 0);

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    Arrays.sort(count, (a, b) -> Integer.compare(b, a));

    for (int i = 0; i < 26; ++i)
      ans += count[i] * (i / 9 + 1);

    return ans;
  }
}
