class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> set{begin(nums1), end(nums1)};

    for (const int num : nums2)
      if (set.erase(num))
        ans.push_back(num);

    return ans;
  }
};
