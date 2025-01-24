class Solution {
 public:
  long long maxSum(vector<int>& nums, int m, int k) {
    long ans = 0;
    long sum = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ++count[nums[i]];
      if (i >= k) {
        const int numToRemove = nums[i - k];
        sum -= numToRemove;
        if (--count[numToRemove] == 0)
          count.erase(numToRemove);
      }
      if (count.size() >= m)
        ans = max(ans, sum);
    }

    return ans;
  }
};
