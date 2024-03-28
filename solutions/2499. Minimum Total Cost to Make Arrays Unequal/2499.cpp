class Solution {
 public:
  long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    long long ans = 0;
    int maxFreq = 0;
    int maxFreqNum = 0;
    int shouldBeSwapped = 0;
    vector<int> conflictedNumCount(n + 1);

    // Collect the indices i s.t. nums1[i] == nums2[i] and record their
    // `maxFreq` and `maxFreqNum`.
    for (int i = 0; i < n; ++i)
      if (nums1[i] == nums2[i]) {
        const int conflictedNum = nums1[i];
        if (++conflictedNumCount[conflictedNum] > maxFreq) {
          maxFreq = conflictedNumCount[conflictedNum];
          maxFreqNum = conflictedNum;
        }
        ++shouldBeSwapped;
        ans += i;
      }

    // Collect the indices with nums1[i] != nums2[i] that contribute less cost.
    // This can be greedily achieved by iterating from 0 to n - 1.
    for (int i = 0; i < n; ++i) {
      // Since we have over `maxFreq * 2` spaces, `maxFreqNum` can be
      // successfully distributed, so no need to collectextra spaces.
      if (maxFreq * 2 <= shouldBeSwapped)
        break;
      if (nums1[i] == nums2[i])
        continue;
      // The numbers == `maxFreqNum` worsen the result since they increase the
      // `maxFreq`.
      if (nums1[i] == maxFreqNum || nums2[i] == maxFreqNum)
        continue;
      ++shouldBeSwapped;
      ans += i;
    }

    return maxFreq * 2 > shouldBeSwapped ? -1 : ans;
  }
};
