class Solution {
  public int numberOfArrays(int[] differences, int lower, int upper) {
    long prefix = 0;
    long mn = 0; // Starts from 0.
    long mx = 0; // Starts from 0.

    for (final int d : differences) {
      prefix += d;
      mn = Math.min(mn, prefix);
      mx = Math.max(mx, prefix);
    }

    return (int) Math.max(0L, (upper - lower) - (mx - mn) + 1);
  }
}
