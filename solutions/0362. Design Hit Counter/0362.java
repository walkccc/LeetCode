class HitCounter {
  /**
   * Record a hit.
   *
   * @param timestamp - The current timestamp (in seconds granularity).
   */
  public void hit(int timestamp) {
    final int i = timestamp % 300;

    if (timestamps[i] == timestamp) {
      ++hits[i];
    } else {
      timestamps[i] = timestamp;
      hits[i] = 1; // reset hit count to 1
    }
  }

  /**
   * Return the number of hits in the past 5 minutes.
   *
   * @param timestamp - The current timestamp (in seconds granularity).
   */
  public int getHits(int timestamp) {
    int countHits = 0;

    for (int i = 0; i < 300; ++i)
      if (timestamp - timestamps[i] < 300)
        countHits += hits[i];

    return countHits;
  }

  private int[] timestamps = new int[300];
  private int[] hits = new int[300];
}
