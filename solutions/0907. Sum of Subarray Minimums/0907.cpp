class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    const int n = arr.size();
    long ans = 0;
    // prev[i] := index k s.t. arr[k] is the prev min in arr[:i]
    vector<int> prev(n, -1);
    // next[i] := index k s.t. arr[k] is the next min in arr[i + 1:]
    vector<int> next(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && arr[stack.top()] > arr[i]) {
        const int index = stack.top();
        stack.pop();
        next[index] = i;
      }
      if (!stack.empty())
        prev[i] = stack.top();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
      ans += static_cast<long>(arr[i]) * (i - prev[i]) * (next[i] - i);
      ans %= kMod;
    }

    return ans;
  }
};
