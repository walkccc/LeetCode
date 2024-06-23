class Solution {
 public:
  long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    if (k == 0)
      return nums1 == nums2 ? 0 : -1;

    long ans = 0;
    // the number of increments - the number of decrements
    long opsDiff = 0;

    for (int i = 0; i < nums1.size(); ++i) {
      const int diff = nums1[i] - nums2[i];
      if (diff == 0)
        continue;
      if (diff % k != 0)
        return -1;
      const int ops = diff / k;
      opsDiff += ops;
      ans += abs(ops);
    }

    return opsDiff == 0 ? ans / 2 : -1;
  }
};
