class Solution {
 public:
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
    vector<int> keepAt(nums1.size(), INT_MAX);
    vector<int> swapAt(nums1.size(), INT_MAX);
    keepAt[0] = 0;
    swapAt[0] = 1;

    for (int i = 1; i < nums1.size(); ++i) {
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        keepAt[i] = keepAt[i - 1];
        swapAt[i] = swapAt[i - 1] + 1;
      }
      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        keepAt[i] = min(keepAt[i], swapAt[i - 1]);
        swapAt[i] = min(swapAt[i], keepAt[i - 1] + 1);
      }
    }

    return min(keepAt.back(), swapAt.back());
  }
};
