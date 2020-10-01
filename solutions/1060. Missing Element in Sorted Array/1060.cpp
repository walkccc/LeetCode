class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int l = 0;
    int r = nums.size();

    // # of missing numbers in [nums[0], nums[i]]
    auto countMissing = [&](int i) { return nums[i] - nums[0] - i; };

    // find the first index l s.t. countMissing(l) >= k
    while (l < r) {
      const int m = l + (r - l) / 2;
      if (countMissing(m) < k)
        l = m + 1;
      else
        r = m;
    }

    return nums[l - 1] + (k - countMissing(l - 1));
  }
};