class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    // If the size of nums1 is m and the size of nums2 is n, then each number in
    // nums1 is repeated n times and each number in nums2 is repeated m times.
    const int xors1 = accumulate(nums1.begin(), nums1.end(), 0, bit_xor<>());
    const int xors2 = accumulate(nums2.begin(), nums2.end(), 0, bit_xor<>());
    return (nums1.size() % 2 * xors2) ^ (nums2.size() % 2 * xors1);
  }
};
