class Solution {
  public int numberOfArrays(int[] differences, int lower, int upper) {
    long prefix = 0;
    long min = 0; // Starts from 0.
    long max = 0; // Starts from 0.

    for (final int d : differences) {
      prefix += d;
      min = Math.min(min, prefix);
      max = Math.max(max, prefix);
    }

    return (int) Math.max(0L, (upper - lower) - (max - min) + 1);
  }
}
