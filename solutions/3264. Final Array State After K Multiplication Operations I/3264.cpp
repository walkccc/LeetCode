class Solution {
 public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    vector<int> ans(nums.size());
    using P = pair<int, int>;  // (nums[i], i)
    priority_queue<P, vector<P>, greater<>> minHeap;

    for (int i = 0; i < nums.size(); ++i)
      minHeap.emplace(nums[i], i);

    while (k-- > 0) {
      const auto [num, i] = minHeap.top();
      minHeap.pop();
      minHeap.emplace(num * multiplier, i);
    }

    while (!minHeap.empty()) {
      const auto [num, i] = minHeap.top();
      minHeap.pop();
      ans[i] = num;
    }

    return ans;
  }
};
