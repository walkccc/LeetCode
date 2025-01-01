class Solution {
 public:
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    constexpr int kMod = 1'000'000'007;
    // Keep the running the sum of `nums1` and `nums2` before the next
    // rendezvous. Since `nums1` and `nums2` are increasing, move forward on the
    // smaller one to ensure we don't miss any rendezvous. When meet rendezvous,
    // choose the better path.
    long ans = 0;
    // sum(nums1) in (the prevoious rendezvous, the next rendezvous)
    long sum1 = 0;
    // sum(nums2) in (the prevoious rendezvous, the next rendezvous)
    long sum2 = 0;
    int i = 0;  // nums1's index
    int j = 0;  // nums2's index

    while (i < nums1.size() && j < nums2.size())
      if (nums1[i] < nums2[j]) {
        sum1 += nums1[i++];
      } else if (nums1[i] > nums2[j]) {
        sum2 += nums2[j++];
      } else {  // An rendezvous happens.
        ans += max(sum1, sum2) + nums1[i];
        sum1 = 0;
        sum2 = 0;
        ++i;
        ++j;
      }

    while (i < nums1.size())
      sum1 += nums1[i++];

    while (j < nums2.size())
      sum2 += nums2[j++];

    return (ans + max(sum1, sum2)) % kMod;
  }
};
