class Solution {
 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long l = 1;
    long long r =
        *min_element(begin(time), end(time)) * static_cast<long>(totalTrips);

    while (l < r) {
      const long long m = (l + r) / 2;
      if (numTrips(time, m) >= totalTrips)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  long numTrips(const vector<int>& times, long m) {
    return accumulate(begin(times), end(times), 0L,
                      [&](long subtotal, int t) { return subtotal + m / t; });
  }
};
