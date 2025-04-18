class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    constexpr int maxZeros = 1;
    int ans = 0;
    queue<int> q;  // Store indices of zero.

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (nums[r] == 0)
        q.push(r);
      if (q.size() > maxZeros)
        l = q.front() + 1, q.pop();
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
