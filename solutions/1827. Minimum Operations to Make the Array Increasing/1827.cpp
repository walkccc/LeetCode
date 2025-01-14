class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    int last = 0;

    for (const int num : nums) {
      ans += max(0, last - num + 1);
      last = max(num, last + 1);
    }

    return ans;
  }
};
