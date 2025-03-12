class Solution {
 public:
  int maxSumMinProduct(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    stack<int> stack;
    vector<long> prefix(nums.size() + 1);

    for (int i = 0; i < nums.size(); ++i)
      prefix[i + 1] = prefix[i] + nums[i];

    for (int i = 0; i <= nums.size(); ++i) {
      while (!stack.empty() &&
             (i == nums.size() || nums[stack.top()] > nums[i])) {
        const int minVal = nums[stack.top()];
        stack.pop();
        const long sum =
            stack.empty() ? prefix[i] : prefix[i] - prefix[stack.top() + 1];
        ans = max(ans, minVal * sum);
      }
      stack.push(i);
    }

    return ans % kMod;
  }
};
