class Solution {
 public:
  vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    const int n = nums1.size();
    vector<long long> ans(n);
    vector<pair<int, int>> numAndIndexes;
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int i = 0; i < n; i++)
      numAndIndexes.emplace_back(nums1[i], i);

    ranges::sort(numAndIndexes);

    const int firstIndex = numAndIndexes[0].second;
    minHeap.push(nums2[firstIndex]);
    long sum = nums2[firstIndex];

    for (int i = 1; i < n; ++i) {
      const auto& [currNum, currIndex] = numAndIndexes[i];
      const auto& [prevNum, prevIndex] = numAndIndexes[i - 1];
      if (currNum == prevNum)
        ans[currIndex] = ans[prevIndex];
      else
        ans[currIndex] = sum;
      minHeap.push(nums2[currIndex]);
      sum += nums2[currIndex];
      if (minHeap.size() == k + 1)
        sum -= minHeap.top(), minHeap.pop();
    }

    return ans;
  }
};
