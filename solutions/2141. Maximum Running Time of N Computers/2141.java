class Solution {
  public long maxRunTime(int n, int[] batteries) {
    long sum = Arrays.stream(batteries).asLongStream().sum();

    Arrays.sort(batteries);

    // The maximum battery is greater than the average, so it can last forever.
    // Reduce the problem from size n to size n - 1.
    int i = batteries.length - 1;
    while (batteries[i] > sum / n) {
      sum -= batteries[i--];
      --n;
    }

    // If the maximum battery <= average running time, it won't be waste, and so
    // do smaller batteries.
    return sum / n;
  }
}
