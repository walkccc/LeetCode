class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long sum = accumulate(begin(batteries), end(batteries), 0LL);

    sort(begin(batteries), end(batteries));

    // max battery is greater than the average, so it can last forever
    // reduce the problem from size n to size n - 1
    while (batteries.back() > sum / n) {
      sum -= batteries.back(), batteries.pop_back();
      --n;
    }

    // if the max battery <= average running time,
    // it won't be waste, and so do smaller batteries
    return sum / n;
  }
};
