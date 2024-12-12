class Solution {
 public:
  vector<long long> maximumSegmentSum(vector<int>& nums,
                                      vector<int>& removeQueries) {
    const int n = nums.size();
    long maxSum = 0;
    vector<long long> ans(n);
    // For the segment [l, r], record its sum in sum[l] and sum[r]
    vector<long long> sum(n);
    // For the segment [l, r], record its count in count[l] and count[r]
    vector<int> count(n);

    for (int i = n - 1; i >= 0; --i) {
      ans[i] = maxSum;
      const int j = removeQueries[i];

      // Calculate `segmentSum`.
      const long leftSum = j > 0 ? sum[j - 1] : 0;
      const long rightSum = j + 1 < n ? sum[j + 1] : 0;
      const long segmentSum = nums[j] + leftSum + rightSum;

      // Calculate `segmentCount`.
      const int leftCount = j > 0 ? count[j - 1] : 0;
      const int rightCount = j + 1 < n ? count[j + 1] : 0;
      const int segmentCount = 1 + leftCount + rightCount;

      // Update the sum and count of the segment [l, r].
      const int l = j - leftCount;
      const int r = j + rightCount;
      sum[l] = segmentSum;
      sum[r] = segmentSum;
      count[l] = segmentCount;
      count[r] = segmentCount;
      maxSum = max(maxSum, segmentSum);
    }

    return ans;
  }
};
