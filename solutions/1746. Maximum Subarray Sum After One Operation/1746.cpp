class Solution {
 public:
  int maxSumAfterOperation(vector<int>& nums) {
    int ans = INT_MIN;
    int regular = 0;
    int squared = 0;

    for (const int num : nums) {
      squared = max({num * num, regular + num * num, squared + num});
      regular = max(num, regular + num);
      ans = max(ans, squared);
    }

    return ans;
  }
};
