class Solution {
  public double[] sampleStats(int[] count) {
    final int n = Arrays.stream(count).sum();
    return new double[] {
        getMinimum(count),                                          //
        getMaximum(count),                                          //
        getMean(count, n),                                          //
        (getLeftMedian(count, n) + getRightMedian(count, n)) / 2.0, //
        getMode(count),
    };
  }

  private double getMinimum(int[] count) {
    for (int i = 0; i < count.length; ++i)
      if (count[i] > 0)
        return i;
    return -1;
  }

  private double getMaximum(int[] count) {
    for (int i = count.length - 1; i >= 0; --i)
      if (count[i] > 0)
        return i;
    return -1;
  }

  private double getMean(int[] count, double n) {
    double mean = 0;
    for (int i = 0; i < count.length; ++i)
      mean += ((long) i * (long) count[i]) / n;
    return mean;
  }

  private double getLeftMedian(int[] count, double n) {
    int numCount = 0;
    for (int i = 0; i < count.length; ++i) {
      numCount += count[i];
      if (numCount >= n / 2)
        return i;
    }
    return -1;
  }

  private double getRightMedian(int[] count, double n) {
    int numCount = 0;
    for (int i = count.length - 1; i >= 0; --i) {
      numCount += count[i];
      if (numCount >= n / 2)
        return i;
    }
    return -1;
  }

  private double getMode(int[] count) {
    int mode = -1;
    int maxCount = 0;
    for (int i = 0; i < count.length; ++i)
      if (count[i] > maxCount) {
        maxCount = count[i];
        mode = i;
      }
    return mode;
  }
}
