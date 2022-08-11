class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans(2);
    unordered_set<int> set1{begin(nums1), end(nums1)};
    unordered_set<int> set2{begin(nums2), end(nums2)};

    for (const int num : set1)
      if (!set2.count(num))
        ans[0].push_back(num);

    for (const int num : set2)
      if (!set1.count(num))
        ans[1].push_back(num);

    return ans;
  }
};
