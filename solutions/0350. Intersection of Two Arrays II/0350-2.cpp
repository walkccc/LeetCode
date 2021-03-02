class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    // What if the given array is already sorted?
    // How would you optimize your algorithm?

    vector<int> ans;
    int i = 0;  // nums1's index
    int j = 0;  // nums2's index

    while (i < nums1.size() && j < nums2.size())
      if (nums1[i] < nums2[j]) {
        ++i;
      } else if (nums1[i] > nums2[j]) {
        ++j;
      } else {
        ans.push_back(nums1[i]);
        ++i;
        ++j;
      }

    return ans;
  }
};
