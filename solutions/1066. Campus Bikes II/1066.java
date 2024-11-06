class Solution {
  public int assignBikes(int[][] workers, int[][] bikes) {
    int[] mem = new int[1 << bikes.length];
    Arrays.fill(mem, Integer.MAX_VALUE);
    return assignBikes(workers, bikes, 0, 0, mem);
  }

  // Returns the minimum Manhattan distances to assign bikes to
  // workers[workerIndex..n), where `used` is the bitmask of the used bikes.
  private int assignBikes(int[][] workers, int[][] bikes, int workerIndex, int used, int[] mem) {
    if (workerIndex == workers.length)
      return 0;
    if (mem[used] != Integer.MAX_VALUE)
      return mem[used];

    for (int bikeIndex = 0; bikeIndex < bikes.length; bikeIndex++)
      if ((used >> bikeIndex & 1) == 0)
        mem[used] = Math.min(mem[used], dist(workers[workerIndex], bikes[bikeIndex]) +
                                            assignBikes(workers, bikes, workerIndex + 1,
                                                        used | (1 << bikeIndex), mem));

    return mem[used];
  }

  private int dist(int[] p1, int[] p2) {
    return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
  }
}
