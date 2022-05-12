class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));

    int l = 0;
    int r = nums.back() - nums.front();

    while (l < r) {
      const int m = (l + r) / 2;
      if (pairDistancesNoGreaterThan(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int pairDistancesNoGreaterThan(const vector<int>& nums, int m) {
    int count = 0;
    int j = 1;
    // for each index i, find the first index j s.t. nums[j] > nums[i] + m,
    // so pairDistancesNoGreaterThan for index i will be j - i - 1
    for (int i = 0; i < nums.size(); ++i) {
      while (j < nums.size() && nums[j] <= nums[i] + m)
        ++j;
      count += j - i - 1;
    }
    return count;
  }
};
