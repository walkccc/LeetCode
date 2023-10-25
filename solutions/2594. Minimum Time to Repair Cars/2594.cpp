class Solution {
 public:
  long long repairCars(vector<int>& ranks, int cars) {
    long long l = 0;
    long long r = 1LL * ranges::min(ranks) * cars * cars;

    while (l < r) {
      const long long m = (l + r) / 2;
      if (numCarsFixed(ranks, m) >= cars)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  long long numCarsFixed(const vector<int>& ranks, long long minutes) {
    long long carsFixed = 0;
    //    r * n^2 = minutes
    // -> n = sqrt(minutes / r)
    for (const int rank : ranks)
      carsFixed += sqrt(minutes / rank);
    return carsFixed;
  }
};
