class Solution {
 public:
  long long repairCars(vector<int>& ranks, int cars) {
    long l = 0;
    long r = static_cast<long>(ranges::min(ranks)) * cars * cars;

    while (l < r) {
      const long m = (l + r) / 2;
      if (numCarsFixed(ranks, m) >= cars)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  long numCarsFixed(const vector<int>& ranks, long minutes) {
    long carsFixed = 0;
    //    r * n^2 = minutes
    // -> n = sqrt(minutes / r)
    for (const int rank : ranks)
      carsFixed += sqrt(minutes / rank);
    return carsFixed;
  }
};
