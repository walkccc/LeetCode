class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
      return -1;

    int sum1 = accumulate(begin(nums1), end(nums1), 0);
    int sum2 = accumulate(begin(nums2), end(nums2), 0);
    if (sum1 > sum2)
      return minOperations(nums2, nums1);

    int ans = 0;
    // increases in nums1 & decreases in nums2
    vector<int> count(6);

    for (const int num : nums1)
      ++count[6 - num];

    for (const int num : nums2)
      ++count[num - 1];

    for (int i = 5; sum2 > sum1;) {
      while (count[i] == 0)
        --i;
      sum1 += i;
      --count[i];
      ++ans;
    }

    return ans;
  }
};
