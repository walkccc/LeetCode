class Solution {
  public int minSwaps(String s) {
    final int ones = (int) s.chars().filter(c -> c == '1').count();
    final int zeros = s.length() - ones;
    if (Math.abs(ones - zeros) > 1)
      return -1;
    if (ones > zeros)
      return countSwaps(s, '1');
    if (zeros > ones)
      return countSwaps(s, '0');
    return Math.min(countSwaps(s, '1'), countSwaps(s, '0'));
  }

  private int countSwaps(final String s, char curr) {
    int swaps = 0;
    for (final char c : s.toCharArray()) {
      if (c != curr)
        ++swaps;
      curr ^= 1;
    }
    return swaps / 2;
  }
}
