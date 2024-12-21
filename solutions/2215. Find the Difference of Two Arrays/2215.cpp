class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    const unordered_set<int> set1{nums1.begin(), nums1.end()};
    const unordered_set<int> set2{nums2.begin(), nums2.end()};
    vector<vector<int>> ans(2);

    for (const int num : set1)
      if (!set2.contains(num))
        ans[0].push_back(num);

    for (const int num : set2)
      if (!set1.contains(num))
        ans[1].push_back(num);

    return ans;
  }
};
