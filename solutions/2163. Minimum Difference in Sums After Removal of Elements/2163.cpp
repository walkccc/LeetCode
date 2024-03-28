class Solution {
 public:
  long long minimumDifference(vector<int>& nums) {
    const int n = nums.size() / 3;
    long long ans = LLONG_MAX;
    long long leftSum = 0;
    long long rightSum = 0;
    // The left part should be as small as possible.
    priority_queue<int> maxHeap;
    // The right part should be as big as possible.
    priority_queue<int, vector<int>, greater<>> minHeap;
    // minLeftSum[i] := the minimum of the sum of n nums in nums[0..i)
    vector<long long> minLeftSum(nums.size());

    for (int i = 0; i < 2 * n; ++i) {
      maxHeap.push(nums[i]);
      leftSum += nums[i];
      if (maxHeap.size() == n + 1)
        leftSum -= maxHeap.top(), maxHeap.pop();
      if (maxHeap.size() == n)
        minLeftSum[i] = leftSum;
    }

    for (int i = nums.size() - 1; i >= n; --i) {
      minHeap.push(nums[i]);
      rightSum += nums[i];
      if (minHeap.size() == n + 1)
        rightSum -= minHeap.top(), minHeap.pop();
      if (minHeap.size() == n)
        ans = min(ans, minLeftSum[i - 1] - rightSum);
    }

    return ans;
  }
};
