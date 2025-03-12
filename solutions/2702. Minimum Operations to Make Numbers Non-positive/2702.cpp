class Solution {
 public:
  int minOperations(vector<int>& nums, int x, int y) {
    int l = 0;
    int r = ranges::max(nums);

    while (l < r) {
      const int m = (l + r) / 2;
      if (isPossible(nums, x, y, m))
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Returns true if it's possible to make all `nums` <= 0 using m operations.
  bool isPossible(const vector<int>& nums, int x, int y, int m) {
    long additionalOps = 0;
    // If we want m operations, first decrease all the numbers by y * m. Then,
    // we have m operations to select indices to decrease them by x - y.
    for (const int num : nums)
      additionalOps +=
          max(0L, (num - static_cast<long>(y) * m + x - y - 1) / (x - y));
    return additionalOps <= m;
  }
};
