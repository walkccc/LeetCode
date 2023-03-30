class Solution {
 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    constexpr int kMod = 1'000'000'007;
    long sumDiff = 0;
    long maxDecrement = 0;
    set<int> sorted(begin(nums1), end(nums1));

    for (int i = 0; i < nums1.size(); ++i) {
      const long currDiff = abs(nums1[i] - nums2[i]);
      sumDiff += currDiff;
      const auto it = sorted.lower_bound(nums2[i]);
      if (it != begin(sorted))
        maxDecrement = max(maxDecrement, currDiff - abs(*prev(it) - nums2[i]));
      if (it != end(sorted))
        maxDecrement = max(maxDecrement, currDiff - abs(*it - nums2[i]));
    }

    return (sumDiff - maxDecrement) % kMod;
  }
};
