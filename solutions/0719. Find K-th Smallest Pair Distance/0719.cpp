class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));

    int l = 0;
    int r = nums.back() - nums.front();

    auto pairDistancesNoGreaterThan = [&](int m) {
      int count = 0;
      // for each index i, find the first index j s.t. nums[j] > nums[i] + m,
      // so pairDistancesNoGreaterThan for index i will be j - i - 1
      for (int i = 0, j = 1; i < nums.size(); ++i) {
        while (j < nums.size() && nums[j] <= nums[i] + m)
          ++j;
        count += j - i - 1;
      }
      return count;
    };

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (pairDistancesNoGreaterThan(m) < k)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};