class Solution {
 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long l = 1;
    long r = static_cast<long>(ranges::min(time)) * totalTrips;

    while (l < r) {
      const long m = (l + r) / 2;
      if (numTrips(time, m) >= totalTrips)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  long numTrips(const vector<int>& times, long m) {
    return accumulate(times.begin(), times.end(), 0L,
                      [&](long subtotal, int t) { return subtotal + m / t; });
  }
};
