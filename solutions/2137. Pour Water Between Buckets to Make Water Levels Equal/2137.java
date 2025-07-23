class Solution {
  public double equalizeWater(int[] buckets, int loss) {
    final double ERR = 1e-5;
    final double PERCENTAGE = (100 - loss) / (double) 100;
    double l = 0.0;
    double r = Arrays.stream(buckets).max().getAsInt();

    while (r - l > ERR) {
      final double m = (l + r) / 2;
      if (canFill(buckets, m, PERCENTAGE))
        l = m;
      else
        r = m;
    }

    return l;
  }

  private boolean canFill(int[] buckets, double target, double PERCENTAGE) {
    double extra = 0.0;
    double need = 0.0;
    for (final int bucket : buckets)
      if (bucket > target)
        extra += bucket - target;
      else
        need += target - bucket;
    return extra * PERCENTAGE >= need;
  };
}
