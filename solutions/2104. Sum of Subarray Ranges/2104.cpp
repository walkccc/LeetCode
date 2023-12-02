class Solution {
 public:
  long long subArrayRanges(vector<int>& nums) {
    return subarraySum(nums, less<int>()) - subarraySum(nums, greater<>());
  }

 private:
  long long subarraySum(const vector<int>& A,
                        const function<int(int, int)>& op) {
    const int n = A.size();
    long long ans = 0;
    vector<int> prev(n, -1);
    vector<int> next(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && op(A[stack.top()], A[i])) {
        const int index = stack.top();
        stack.pop();
        next[index] = i;
      }
      if (!stack.empty())
        prev[i] = stack.top();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i)
      ans += static_cast<long>(A[i]) * (i - prev[i]) * (next[i] - i);

    return ans;
  }
};
