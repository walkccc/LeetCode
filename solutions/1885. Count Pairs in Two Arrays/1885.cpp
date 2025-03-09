class Solution {
 public:
  long long countPairs(vector<int>& nums1, vector<int>& nums2) {
    long ans = 0;
    vector<int> arr(nums1.size());

    for (int i = 0; i < arr.size(); ++i)
      arr[i] = nums1[i] - nums2[i];

    ranges::sort(arr);

    for (int i = 0; i < arr.size(); ++i) {
      const auto it = lower_bound(arr.begin() + i + 1, arr.end(), -arr[i] + 1);
      ans += arr.cend() - it;
    }

    return ans;
  }
};
