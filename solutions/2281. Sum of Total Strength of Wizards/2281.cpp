class Solution {
 public:
  int totalStrength(vector<int>& strength) {
    constexpr int kMod = 1'000'000'007;
    const int n = strength.size();
    vector<long> prefix(n);
    vector<long> prefixOfPrefix(n + 1);
    // left[i] := the next index on the left (if any) s.t.
    // nums[left[i]] <= nums[i]
    vector<int> left(n, -1);
    // right[i] := the next index on the right (if any) s.t.
    // nums[right[i]] < nums[i]
    vector<int> right(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i)
      prefix[i] = i == 0 ? strength[0] : (strength[i] + prefix[i - 1]) % kMod;

    for (int i = 0; i < n; ++i)
      prefixOfPrefix[i + 1] = (prefixOfPrefix[i] + prefix[i]) % kMod;

    for (int i = n - 1; i >= 0; --i) {
      while (!stack.empty() && strength[stack.top()] >= strength[i])
        left[stack.top()] = i, stack.pop();
      stack.push(i);
    }

    stack = std::stack<int>();

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && strength[stack.top()] > strength[i])
        right[stack.top()] = i, stack.pop();
      stack.push(i);
    }

    long ans = 0;

    // For each strength[i] as minimum, calculate sum.
    for (int i = 0; i < n; ++i) {
      const int l = left[i];
      const int r = right[i];
      const long leftSum = prefixOfPrefix[i] - prefixOfPrefix[max(0, l)];
      const long rightSum = prefixOfPrefix[r] - prefixOfPrefix[i];
      const int leftLen = i - l;
      const int rightLen = r - i;
      ans += strength[i] *
             (rightSum * leftLen % kMod - leftSum * rightLen % kMod + kMod) %
             kMod;
      ans %= kMod;
    }

    return ans;
  }
};
