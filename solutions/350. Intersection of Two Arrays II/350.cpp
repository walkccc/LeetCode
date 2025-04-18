class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return intersect(nums2, nums1);

    vector<int> ans;
    unordered_map<int, int> count;

    for (const int num : nums1)
      ++count[num];

    for (const int num : nums2)
      if (const auto it = count.find(num);
          it != count.cend() && it->second-- > 0)
        ans.push_back(num);

    return ans;
  }
};
