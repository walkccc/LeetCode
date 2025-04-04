class Solution {
 public:
  // Same as 1383. Maximum Performance of a Team
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    long ans = 0;
    long sum = 0;
    // (nums2[i], nums1[i]) sorted by nums2[i] in descending order
    vector<pair<int, int>> A;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int i = 0; i < nums1.size(); ++i)
      A.emplace_back(nums2[i], nums1[i]);

    ranges::sort(A, greater<>());

    for (const auto& [num2, num1] : A) {
      minHeap.push(num1);
      sum += num1;
      if (minHeap.size() > k)
        sum -= minHeap.top(), minHeap.pop();
      if (minHeap.size() == k)
        ans = max(ans, sum * num2);
    }

    return ans;
  }
};
