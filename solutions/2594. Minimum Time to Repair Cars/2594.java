class Solution {
  public long repairCars(int[] ranks, int cars) {
    long l = 0;
    long r = (long) Arrays.stream(ranks).min().getAsInt() * cars * cars;

    while (l < r) {
      final long m = (l + r) / 2;
      if (numCarsFixed(ranks, m) >= cars)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private long numCarsFixed(int[] ranks, long minutes) {
    long carsFixed = 0;
    //    r * n^2 = minutes
    // -> n = sqrt(minutes / r)
    for (final int rank : ranks)
      carsFixed += Math.sqrt(minutes / rank);
    return carsFixed;
  }
}
