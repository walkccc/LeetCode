class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    int ans = 0;
    unordered_map<int, int> count;

    for (const int a : nums1)
      for (const int b : nums2)
        ++count[a + b];

    for (const int c : nums3)
      for (const int d : nums4)
        if (count.count(-c - d))
          ans += count[-c - d];

    return ans;
  }
};
