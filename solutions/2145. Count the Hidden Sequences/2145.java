class Solution {
  public int numberOfArrays(int[] differences, int lower, int upper) {
    // Starts from 0, so prefix[0] = 0.
    // Changing prefix[0] to any other number doesn't affect the answer.
    long[] prefix = new long[differences.length + 1];

    for (int i = 0; i < differences.length; ++i)
      prefix[i + 1] += prefix[i] + differences[i];

    final long max = Arrays.stream(prefix).max().getAsLong();
    final long min = Arrays.stream(prefix).min().getAsLong();
    return (int) Math.max(0L, (upper - lower) - (max - min) + 1);
  }
}
