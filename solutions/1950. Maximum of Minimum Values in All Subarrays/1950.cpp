class Solution {
 public:
  // Similar to 1950. Maximum of Minimum Values in All Subarrays
  vector<int> findMaximums(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);
    // prevMin[i] := the index k s.t.
    // nums[k] is the previous minimum in nums[0..n)
    vector<int> prevMin(n, -1);
    // nextMin[i] := the index k s.t.
    // nums[k] is the next minimum innums[i + 1..n)
    vector<int> nextMin(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && nums[stack.top()] > nums[i]) {
        const int index = stack.top();
        stack.pop();
        nextMin[index] = i;
      }
      if (!stack.empty())
        prevMin[i] = stack.top();
      stack.push(i);
    }

    // For each nums[i], let l = nextMin[i] + 1 and r = nextMin[i] - 1.
    // nums[i] is the minimun in nums[l..r].
    // So, the ans[r - l + 1] will be at least nums[i].
    for (int i = 0; i < n; ++i) {
      const int sz = nextMin[i] - prevMin[i] - 1;
      ans[sz - 1] = max(ans[sz - 1], nums[i]);
    }

    // ans[i] should always >= ans[i + 1..n).
    for (int i = n - 2; i >= 0; --i)
      ans[i] = max(ans[i], ans[i + 1]);

    return ans;
  }
};
