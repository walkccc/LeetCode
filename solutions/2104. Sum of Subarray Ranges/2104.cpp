class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    const auto [prevGt, nextGt] = getPrevNext(nums, less<>());
    const auto [prevLt, nextLt] = getPrevNext(nums, greater<>());
    long ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      ans += static_cast<long>(nums[i]) * (i - prevGt[i]) * (nextGt[i] - i);
      ans -= static_cast<long>(nums[i]) * (i - prevLt[i]) * (nextLt[i] - i);
    }

    return ans;
  }

 private:
  // Returns `prev` and `next`, that store the indices of the nearest numbers
  // that are smaller or larger than the current number depending on `op`.
  pair<vector<int>, vector<int>> getPrevNext(
      const vector<int>& nums, const function<bool(int, int)>& op) {
    const int n = nums.size();
    vector<int> prev(n, -1);
    vector<int> next(n, n);
    stack<int> stack;
    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && op(nums[stack.top()], nums[i])) {
        const int index = stack.top();
        stack.pop();
        next[index] = i;
      }
      if (!stack.empty())
        prev[i] = stack.top();
      stack.push(i);
    }
    return {prev, next};
  }
};
