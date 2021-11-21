class Solution {
  public double[] sampleStats(int[] count) {
    int minimum = 0;
    int maximum = 0;
    double mean = 0;
    int leftMedian = 0;
    int rightMedian = 0;
    int mode = -1;
    int numCount = Arrays.stream(count).sum();
    int newNumCount = 0;
    int maxCount = 0;

    for (int i = 0; i < count.length; ++i)
      if (count[i] > 0) {
        minimum = i;
        break;
      }

    for (int i = count.length - 1; i >= 0; --i)
      if (count[i] > 0) {
        maximum = i;
        break;
      }

    for (int i = 0; i < count.length; ++i)
      mean += (double) (i * count[i]) / (double) numCount;

    for (int i = 0; i < count.length; ++i) {
      newNumCount += count[i];
      if (newNumCount >= numCount / 2) {
        leftMedian = i;
        break;
      }
    }

    newNumCount = 0;

    for (int i = count.length - 1; i >= 0; --i) {
      newNumCount += count[i];
      if (newNumCount >= numCount / 2) {
        rightMedian = i;
        break;
      }
    }

    for (int i = 0; i < count.length; ++i)
      if (count[i] > maxCount) {
        maxCount = count[i];
        mode = i;
      }

    return new double[] {minimum, maximum, mean, (double) (leftMedian + rightMedian) / 2.0, mode};
  }
}
