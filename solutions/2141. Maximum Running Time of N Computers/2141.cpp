class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);

    ranges::sort(batteries);

    // The maximum battery is greater than the average, so it can last forever.
    // Reduce the problem from size n to size n - 1.
    while (batteries.back() > sum / n) {
      sum -= batteries.back(), batteries.pop_back();
      --n;
    }

    // If the maximum battery <= average running time, it won't be waste, and so
    // do smaller batteries.
    return sum / n;
  }
};
