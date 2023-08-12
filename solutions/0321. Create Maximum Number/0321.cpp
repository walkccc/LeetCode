class Solution {
 public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ans;

    for (int k1 = 0; k1 <= k; ++k1) {
      const int k2 = k - k1;
      if (k1 > nums1.size() || k2 > nums2.size())
        continue;
      ans = max(ans, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k2)));
    }

    return ans;
  }

 private:
  vector<int> maxNumber(const vector<int>& nums, int k) {
    if (k == 0)
      return {};

    vector<int> ans;
    int toPop = nums.size() - k;

    for (const int num : nums) {
      while (!ans.empty() && ans.back() < num && toPop-- > 0)
        ans.pop_back();
      ans.push_back(num);
    }

    return {ans.begin(), ans.begin() + k};
  }

 private:
  vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> ans;

    auto s1 = nums1.cbegin();
    auto s2 = nums2.cbegin();

    while (s1 != nums1.cend() || s2 != nums2.cend())
      if (lexicographical_compare(s1, nums1.cend(), s2, nums2.cend()))
        ans.push_back(*s2++);
      else
        ans.push_back(*s1++);

    return ans;
  }
};
