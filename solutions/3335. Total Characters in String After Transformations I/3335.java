class Solution {
  public int lengthAfterTransformations(String s, int t) {
    final int MOD = 1_000_000_007;
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    while (t-- > 0) {
      int[] newCount = new int[26];
      // 'a' -> 'b', 'b' -> 'c', ..., 'y' -> 'z'
      for (int i = 0; i < 25; i++)
        newCount[i + 1] = count[i];
      // 'z' -> 'ab'
      newCount[0] = count[25];
      newCount[1] = (newCount[1] + count[25]) % MOD;
      count = newCount;
    }

    return Arrays.stream(count).reduce(0, (a, b) -> (a + b) % MOD);
  }
}
