class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    constexpr double kErr = 1e-5;
    double l = ranges::min(nums);
    double r = ranges::max(nums);

    while (r - l > kErr) {
      const double m = (l + r) / 2;
      if (check(nums, k, m))
        l = m;
      else
        r = m;
    }

    return l;
  }

 private:
  // Returns true if there's a subarray, where its length >= k and its average
  // sum >= m.
  bool check(const vector<int>& nums, int k, double m) {
    double sum = 0;
    double prevSum = 0;
    double minPrevSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      // Need to substract m for each `num` so that we can check if the sum of
      // the subarray >= 0.
      sum += nums[i] - m;
      if (i >= k) {
        prevSum += nums[i - k] - m;
        minPrevSum = min(minPrevSum, prevSum);
      }
      if (i + 1 >= k && sum >= minPrevSum)
        return true;
    }

    return false;
  };
};
