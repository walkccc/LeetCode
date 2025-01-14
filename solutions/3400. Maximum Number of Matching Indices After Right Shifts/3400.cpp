class Solution {
 public:
  int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    int ans = 0;

    for (int shift = 0; shift < n; ++shift) {
      int matches = 0;
      for (int i = 0; i < n; ++i)
        if (nums1[(i + shift) % n] == nums2[i])
          ++matches;
      ans = max(ans, matches);
    }

    return ans;
  }
};
