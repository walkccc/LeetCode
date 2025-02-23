class Solution {
  public boolean hasAllCodes(String s, int k) {
    final int n = 1 << k;
    if (s.length() < n)
      return false;

    // used[i] := true if i is a substring of `s`
    boolean[] used = new boolean[n];

    int window = k == 1 ? 0 : Integer.parseInt(s.substring(0, k - 1), 2);
    for (int i = k - 1; i < s.length(); ++i) {
      // Include the s[i].
      window = (window << 1) + (s.charAt(i) - '0');
      // Discard the s[i - k].
      window &= n - 1;
      used[window] = true;
    }

    return IntStream.range(0, used.length).mapToObj(i -> used[i]).allMatch(u -> u);
  }
}
