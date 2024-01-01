class Solution {
 public:
  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    return max(kadane(nums1, nums2), kadane(nums2, nums1));
  }

 private:
  // Returns the maximum gain of swapping some numbers in `nums1` with some
  // numbers in `nums2`.
  int kadane(const vector<int>& nums1, const vector<int>& nums2) {
    int gain = 0;
    int maxGain = 0;

    for (int i = 0; i < nums1.size(); ++i) {
      gain = max(0, gain + nums2[i] - nums1[i]);
      maxGain = max(maxGain, gain);
    }

    return maxGain + accumulate(nums1.begin(), nums1.end(), 0);
  }
};
