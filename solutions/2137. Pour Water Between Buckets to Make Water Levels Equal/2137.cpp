class Solution {
 public:
  double equalizeWater(vector<int>& buckets, int loss) {
    constexpr double kErr = 1e-5;
    const double kPercentage = (100 - loss) / (double)100;
    double l = 0.0;
    double r = ranges::max(buckets);

    while (r - l > kErr) {
      const double m = (l + r) / 2;
      if (canFill(buckets, m, kPercentage))
        l = m;
      else
        r = m;
    }

    return l;
  }

 private:
  bool canFill(const vector<int>& buckets, double target, double kPercentage) {
    double extra = 0.0;
    double need = 0.0;
    for (const int bucket : buckets)
      if (bucket > target)
        extra += bucket - target;
      else
        need += target - bucket;
    return extra * kPercentage >= need;
  }
};
