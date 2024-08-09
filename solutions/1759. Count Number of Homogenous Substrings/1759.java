class Solution {
  public int countHomogenous(String s) {
    final int kMod = 1_000_000_007;
    int ans = 0;
    int count = 0;
    char currentChar = '@';

    for (final char c : s.toCharArray()) {
      count = c == currentChar ? count + 1 : 1;
      currentChar = c;
      ans += count;
      ans %= kMod;
    }

    return ans;
  }
}
