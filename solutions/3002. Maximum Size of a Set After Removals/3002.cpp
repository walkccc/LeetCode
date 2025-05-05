class Solution {
 public:
  int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
    const unordered_set<int> set1{nums1.begin(), nums1.end()};
    const unordered_set<int> set2{nums2.begin(), nums2.end()};
    unordered_set<int> common;

    for (const int num1 : set1)
      if (set2.contains(num1))
        common.insert(num1);

    const int n = nums1.size();
    const int n1 = set1.size();
    const int n2 = set2.size();
    const int nc = common.size();
    const int maxUniqueNums1 = min(n1 - nc, n / 2);
    const int maxUniqueNums2 = min(n2 - nc, n / 2);
    return min(n, maxUniqueNums1 + maxUniqueNums2 + nc);
  }
};
