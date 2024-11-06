class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    if (n1 > n2)
      return findMedianSortedArrays(nums2, nums1);

    int l = 0;
    int r = n1;

    while (l <= r) {
      const int partition1 = (l + r) / 2;
      const int partition2 = (n1 + n2 + 1) / 2 - partition1;
      const int maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
      const int maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
      const int minRight1 = partition1 == n1 ? INT_MAX : nums1[partition1];
      const int minRight2 = partition2 == n2 ? INT_MAX : nums2[partition2];
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        return (n1 + n2) % 2 == 0
                   ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) * 0.5
                   : max(maxLeft1, maxLeft2);
      else if (maxLeft1 > minRight2)
        r = partition1 - 1;
      else
        l = partition1 + 1;
    }

    throw;
  }
};
