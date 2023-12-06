class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    const long long sum1 = accumulate(nums1.begin(), nums1.end(), 0LL);
    const long long sum2 = accumulate(nums2.begin(), nums2.end(), 0LL);
    const int zero1 = ranges::count(nums1, 0);
    const int zero2 = ranges::count(nums2, 0);
    if (zero1 == 0 && sum1 < sum2 + zero2)
      return -1;
    if (zero2 == 0 && sum2 < sum1 + zero1)
      return -1;
    return max(sum1 + zero1, sum2 + zero2);
  }
};
