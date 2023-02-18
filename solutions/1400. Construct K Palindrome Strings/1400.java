class Solution {
  public boolean canConstruct(String s, int k) {
    // If the s.length() < k, we cannot finalruct k strings from s.
    if (s.length() < k)
      return false;

    int[] count = new int[26];

    for (final char c : s.toCharArray())
      count[c - 'a'] ^= 1;

    // If the # of characters that have odd counts is > k, the min # of
    // palindrome strings we can finalruct is > k.
    return Arrays.stream(count).filter(c -> c % 2 == 1).count() <= k;
  }
}
