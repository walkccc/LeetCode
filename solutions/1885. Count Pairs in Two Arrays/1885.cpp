class Solution {
 public:
  long long countPairs(vector<int>& nums1, vector<int>& nums2) {
    long ans = 0;
    vector<int> A(nums1.size());

    for (int i = 0; i < A.size(); ++i)
      A[i] = nums1[i] - nums2[i];

    ranges::sort(A);

    for (int i = 0; i < A.size(); ++i) {
      const auto it = lower_bound(A.begin() + i + 1, A.end(), -A[i] + 1);
      ans += A.cend() - it;
    }

    return ans;
  }
};
