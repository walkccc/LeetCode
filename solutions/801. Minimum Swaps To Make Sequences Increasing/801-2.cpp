class Solution {
 public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int keepAt = 0;
    int swapAt = 1;
    int prevKeepAt = 0;
    int prevSwapAt = 1;

    for (int i = 1; i < nums1.size(); ++i) {
      keepAt = INT_MAX;
      swapAt = INT_MAX;
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        keepAt = prevKeepAt;
        swapAt = prevSwapAt + 1;
      }
      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        keepAt = min(keepAt, prevSwapAt);
        swapAt = min(swapAt, prevKeepAt + 1);
      }
      prevKeepAt = keepAt;
      prevSwapAt = swapAt;
    }

    return min(keepAt, swapAt);
  }
};
