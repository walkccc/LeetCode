class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    const int n = nums.size();
    int ans = n + 1;
    deque<int> dq;
    vector<long> prefix{0};

    for (int i = 0; i < n; ++i)
      prefix.push_back(prefix.back() + nums[i]);

    for (int i = 0; i < n + 1; ++i) {
      while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
        ans = min(ans, i - dq.front()), dq.pop_front();
      while (!dq.empty() && prefix[i] <= prefix[dq.back()])
        dq.pop_back();
      dq.push_back(i);
    }

    return ans <= n ? ans : -1;
  }
};
