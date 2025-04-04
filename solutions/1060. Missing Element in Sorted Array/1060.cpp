class Solution {
 public:
  int missingElement(vector<int>& nums, int k) {
    int l = 0;
    int r = nums.size();

    // the number of missing numbers in [nums[0], nums[i]]
    auto nMissing = [&](int i) { return nums[i] - nums[0] - i; };

    // Find the first index l s.t. nMissing(l) >= k
    while (l < r) {
      const int m = (l + r) / 2;
      if (nMissing(m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return nums[l - 1] + (k - nMissing(l - 1));
  }
};
