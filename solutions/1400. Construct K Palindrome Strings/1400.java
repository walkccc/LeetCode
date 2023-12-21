class Solution {
  public boolean canConstruct(String s, int k) {
    // If |s| < k, we cannot construct k strings from the s.
    if (s.length() < k)
      return false;

    int[] count = new int[26];

    for (final char c : s.toCharArray())
      count[c - 'a'] ^= 1;

    // If the number of letters that have odd counts > k, the minimum number of
    // palindromic strings we can construct is > k.
    return Arrays.stream(count).filter(c -> c % 2 == 1).count() <= k;
  }
}
