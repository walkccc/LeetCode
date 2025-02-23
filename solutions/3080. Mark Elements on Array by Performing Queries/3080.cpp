class Solution {
 public:
  vector<long long> unmarkedSumArray(vector<int>& nums,
                                     vector<vector<int>>& queries) {
    vector<long long> ans;
    vector<bool> marked(nums.size());
    long sum = accumulate(nums.begin(), nums.end(), 0L);
    using P = pair<int, int>;  // (nums[i], i)
    priority_queue<P, vector<P>, greater<>> minHeap;

    for (int i = 0; i < nums.size(); ++i)
      minHeap.emplace(nums[i], i);

    for (const vector<int>& query : queries) {
      const int index = query[0];
      const int k = query[1];
      if (!marked[index]) {
        marked[index] = true;
        sum -= nums[index];
      }
      for (int popped = 0; popped < k && !minHeap.empty();) {
        const auto [num, i] = minHeap.top();
        minHeap.pop();
        if (!marked[i]) {
          marked[i] = true;
          sum -= num;
          ++popped;
        }
      }
      ans.push_back(sum);
    }

    return ans;
  }
};
